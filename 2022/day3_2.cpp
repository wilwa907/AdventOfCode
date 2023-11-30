#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string bag1, bag2, bag3;
int linesInFile = 0, sum = 0;

int main()
{
    ifstream infile;
    infile.open("day3.txt"); // Open file
    
    while (getline(infile, bag1))
        {
            linesInFile++;
        }
    infile.close();
    
    infile.open("day3.txt"); // Re-open file

    vector<char> badges;
    for (int i=1; i<=linesInFile/3; i++) // Looping through the amount of groups
    {
        bool check = true;
        infile >> bag1;
        infile >> bag2;
        infile >> bag3;
        
        cout << bag1 << endl;
        cout << bag2 << endl;
        cout << bag3 << endl;
        cout << endl;
            
        for (char& i : bag1) // Loop through first, second and third bag
        {
            for (char& j : bag2)
            {
                for (char& k : bag3)
                {
                    if (i==j && j==k && check) // Check if character appears in all bags and if check = true
                    {
                        check = false; // Set check to false to not add more than one badge for each group
                        cout << "Shared item is: " << i << endl;
                        badges.push_back(i); // Appending all badges into vector named badges
                    }
                }
            }
        }
        
        for (int i=0; i<badges.size(); i++) // Displaying the vector
        {
            cout << badges[i] << " ";
        }
        cout << endl;
    }
    
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (char& i : badges) // Loop through all badges and comparing with the alphabet
    {
        int priority = 0;
        for (char& j : alphabet)
        {
            priority++;
            if (i==j)
            {
                sum = sum + priority; // Adding the priority of the badges to the sum
                cout << sum << endl;
            }
        }
    }
    return 0;
}
