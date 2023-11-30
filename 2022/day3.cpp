#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

string bag, compartments1, compartments2;
int linesInFile = 0, sum = 0;

int main()
{
    ifstream infile;
    infile.open("day3.txt"); // Open file
    
    while (getline(infile, bag))
        {
            linesInFile++;
        }
    infile.close();
    
    infile.open("day3.txt"); // Re-open file

    vector<char> duplicates;
    for (int i=1; i<=linesInFile; i++)
    {
        bool check = true;
        infile >> bag;
        cout << bag << endl;
        compartments1 = bag.substr(0, bag.length()/2); // Split bag into two new strings
        compartments2 = bag.substr(bag.length()/2);
        cout << compartments1 << "  " << compartments2 << endl;
        
        for (char& i : compartments1) // Loop through first and second string
        {
            for (char& j : compartments2)
            {
                if (i==j && check) // Check if character appears in both strings and if check = true
                {
                    check = false; // Set check to false to not add more than one duplicate for each row
                    cout << "Shared item is: " << i << endl;
                    duplicates.push_back(i); // Appending all duplicates into vector named duplicates
                }
            }
        }
        
        for (int i=0; i<duplicates.size(); i++) // Displaying the vector
        {
            cout << duplicates[i] << " ";
        }
        cout << endl;
    }
    
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (char& i : duplicates) // Loop through all duplicates and comparing with the alphabet
    {
        int priority = 0;
        for (char& j : alphabet)
        {
            priority++;
            if (i==j)
            {
                sum = sum + priority; // Adding the priority of the duplicate to the sum
                cout << sum << endl;
            }
        }
    }
    
    return 0;
}
