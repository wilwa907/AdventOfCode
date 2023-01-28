#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void day10()
{
    vector <int> sumStrengths;
    string line, signal;
    int registerX=1, strength=0, cycle=0, strengthTotal=0;
    
    fstream infile;
    infile.open("day10.txt");
    
    while(getline(infile, line))
    {
        signal = line.substr(0, line.find(" "));
        
        if (signal == "addx")
        {   // Load strength
            istringstream(line.substr(4, line.find("\n"))) >> strength;
            sumStrengths.push_back(0); // First cycles nothing happens, add 0
            sumStrengths.push_back(strength); // Second cycle, add signal
        }
        else
            sumStrengths.push_back(0); // If noop, add 0 to keep track of cycles in length of vector
    }
    
    string row(40, ' '); // Allocate 40 positions with blankspaces
    for (int i=0; i<sumStrengths.size(); i++)
    {
        cycle++;
        int pixel = i % 40; // Get pixel 0-39, 6 times
        if (pixel >= registerX-1 && pixel <=registerX+1) // Check if current pixel position is over the sprite => LIGHT UP!
            row[pixel] = '#';
        
        if (cycle % 40 == 0) // If at end of row, print row and clear for next row
        {
            cout << row << endl;
            row = string(40, ' ');
        }
            
        if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220)
            strengthTotal += registerX*cycle;
        registerX += sumStrengths[i]; // After instruction finishes execution, add current strength
    }
    cout << "The sum of these six signal strengths are: " << strengthTotal << endl;
}

int main()
{
    day10();
    return 0;
}
