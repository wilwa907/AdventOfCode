//
//  main.cpp
//  AoC_day4
//
//  Created by William Wärn on 2022-12-23.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int count = 0, linesInFile = 0, elf1min_int, elf1max_int, elf2min_int, elf2max_int;
int elf1_section, elf2_section, overlap;
std::string elf1min, elf1max, elf2min, elf2max;

int main()
{
    std::ifstream infile;
    infile.open("day4.txt");
    
    while (getline(infile, elf1min))
        {
            linesInFile++;
        }
    infile.close();
    
    infile.open("day4.txt"); // Re-open file
    for (int i=1; i<=linesInFile; i++) // Looping through the amount of groups
    {
        bool check = true;
        
        getline(infile, elf1min, '-');
        getline(infile, elf1max, ',');
        getline(infile, elf2min, '-');
        getline(infile, elf2max);
        
        std::cout << elf1min << std::endl;
        std::cout << elf1max << std::endl;
        std::cout << elf2min << std::endl;
        std::cout << elf2max << std::endl;
        
        // Convert from string to int
        std::istringstream(elf1min) >> elf1min_int;
        std::istringstream(elf1max) >> elf1max_int;
        std::istringstream(elf2min) >> elf2min_int;
        std::istringstream(elf2max) >> elf2max_int;
        
        if ((elf1min_int<=elf2min_int && elf2max_int<=elf1max_int) || (elf2min_int<=elf1min_int && elf1max_int<=elf2max_int)) // Check if one elfs assignment is fully contained by the other elfs
        {
            count++;
        }
        
        // Part 2 addition
        for (int i=elf1min_int; i<=elf1max_int; i++) // Looping through first elfs sections
        {
            for (int j=elf2min_int; j<=elf2max_int; j++) // Looping through second elfs sections
            {
                if (i==j && check) // Comparing the sections for the elfs
                {
                    check = false;
                    overlap++;
                }
            }
        }
    }
    infile.close();
    std::cout << "For " << count << " assignment pairs one range fully contain the other." << std::endl;
    std::cout << "The total number of overlaps is " << overlap << ". (Just considering if one section or more overlaps)" << std::endl;
    return 0;
}
