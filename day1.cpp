//
//  main.cpp
//  AoC_day1
//
//  Created by William Wärn on 2022-12-19.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

string food;
int food_int, food_sum, sum, top_three_sum=0;
int top_three[] = {100000,0,0};

int main()
{
    for (int i=1; i<4; i++) // Loop for three Elfs
    {
        ifstream infile;
        infile.open("day1.txt"); // Open file
    
        sum = 0;
        food_sum = 0;
        while (!infile.eof()) // Keep reading until end-of-file
        {
            getline(infile, food);
            cout << food << endl;
            
            istringstream(food) >> food_int; // Convert from string to int
            food_sum += food_int;
        
            
            if (food.empty()) // Check if empty row is found
            {
                food_sum = food_sum - food_int;
                
                if (food_sum>sum && food_sum<top_three[i-1]) // Check if current sum is more than previous
                {                                            // and if current sum is less than previous most
                    sum = food_sum; // Update largest sum
                    top_three[i] = sum; // Add the top three Elf to a list
                    cout << sum << endl;
                    food_sum = 0;
                }
                else
                    food_sum = 0;
            }
        }
        infile.close();
    }
    
    for (int i=0; i<4; i++)
        cout << top_three[i] << " ";
    cout << endl;
    
    for (int i=1; i<4; i++)
        top_three_sum += top_three[i];
    cout << "The sum of the top 3 Elfs are: " << top_three_sum << endl;
    
    return 0;
}
