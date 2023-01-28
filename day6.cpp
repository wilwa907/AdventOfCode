#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool uniqueCharactersPartOne(string str)
{
    if (str[0]==str[1] || str[0]==str[2] || str[0]==str[3] || str[1]==str[2] || str[1]==str[3] || str[2]==str[3]) // Check if all characters are unique
    {
        return false;
    }
    else
        return true;
}

bool uniqueCharactersPartTwo(string str)
{
    for (int i=0; i<str.length(); i++)
    {
        for (int j=0; j<str.length(); j++)
        {
            if (str[i]==str[j] && i!=j) // Check if all characters are unique
            {
                return false;
            }
        }
    }
    return true;
}

void partOne()
{
    string datastream, subString, subChar;
    ifstream infile;
    infile.open("day6.txt");
    
    getline(infile, datastream, '\t');
    cout << datastream << endl;
    
    int count=4, characters=4, term=0;
    for (int i=0; i<datastream.length()-4; i++)
    {
        subString = datastream.substr(i,count); // Picking out the substrings of 4 characters
        cout << subString << endl;
        
        if (uniqueCharactersPartOne(subString)==false && term!=1)
        {
            characters++;
            cout << characters << endl;
        }
        else
        {
            cout << "--STOP--" << endl;
            term = 1;
        }
    }
}

void partTwo()
{
    string datastream, subString, subChar;
    ifstream infile;
    infile.open("day6.txt");
    
    getline(infile, datastream, '\t');
    cout << datastream << endl;
    
    int count=14, characters=14, term=0;
    for (int i=0; i<datastream.length()-14; i++)
    {
        subString = datastream.substr(i,count); // Picking out the substrings of 4 characters
        cout << subString << endl;
        
        if (uniqueCharactersPartTwo(subString)==false && term!=1)
        {
            characters++;
            cout << characters << endl;
        }
        else
        {
            cout << "--STOP--" << endl;
            term = 1;
        }
    }
}

int main()
{
    partOne();
    partTwo();
    
    return 0;
}
