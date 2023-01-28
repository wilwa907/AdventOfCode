#include <fstream>
#include <iostream>
#include <string>
using namespace std;

fstream input;

int sum = 0, smallest = 30000000;

int goDeeper(int findDir)
{
    string line;
    int dirSize = 0;
    while (getline(input, line))
    {   // Check the size of the files in dir and sums them in the variable dirSize
        if (line.at(0) >= '1' && line.at(0) <= '9')
        {
            for (int i = 1; i < line.length(); i++)
            {
                if (line.at(i) == ' ')
                {
                    dirSize += stoi(line.substr(0, i));
                    cout << dirSize << endl;
                }
            }
        }
        else if (line.at(0) == '$')
        {
            if (line.at(2) == 'l')
                continue;
            else if (line.at(5) == '.')
            {
                if (dirSize <= 100000) // If sum of files in dir < 100000 add to sum
                    sum += dirSize;
                
                if (dirSize >= findDir && dirSize < smallest)
                    smallest = dirSize;
                
                return dirSize; // Always return size of directory
            }
            else
                dirSize += goDeeper(findDir);// If entering a new dir run again
        }
    }
    if (dirSize <= 100000) sum += dirSize;
    if (dirSize >= findDir && dirSize < smallest) smallest = dirSize;
    return dirSize;
}

int main()
{
    input.open("day7.txt");
    if (!input.is_open()) return -23;
    int total = goDeeper(0);
    
    cout << "The total size of directories under size 100000 is " << sum << endl;
    
    input.clear();
    input.seekg(0);
    smallest = 30000000;
    goDeeper(30000000 - (70000000 - total));

    
    cout << "The size of the directory to delete is " << smallest << ".";
    
    input.seekg(0);
}
