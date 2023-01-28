#include <iostream>
#include <fstream>
#include <sstream>
#include <tuple>
#include <cmath>
#include <map>
using namespace std;

string line, operation, amountString;
int amount;
char buffer[10]; // Create buffer and buffer size
int bufferSize = 10;

void day9(int knots, int part)
{
    fstream infile;
    infile.open("day9.txt");
    
    struct Coord // Creating a struct containing x- and y-coordinate
    {
        int x = 0;
        int y = 0;
    };

    Coord rope[knots]; // Initialize struct with a number of x- and y-coordinates
    map <string, bool> visited;
    visited.insert({"0:0", true});

    while (getline(infile,line))
    {
        operation = line.substr(0, line.find(" "));
        amountString = line.substr(2, line.find("\n"));
        istringstream(amountString) >> amount;

        for (int i=0; i<amount; i++)
        {
            if (operation == "R") rope[0].x++;
            else if (operation == "L") rope[0].x--;
            else if (operation == "U") rope[0].y++;
            else if (operation == "D") rope[0].y--;
            
            for (int j=1; j<knots; j++)
            {
                int dx = (rope[j-1].x - rope[j].x);
                int dy = (rope[j-1].y - rope[j].y);

                if (sqrt(pow(dx, 2) + pow(dy, 2)) > sqrt(2)) // Pythagorean theorem, if the distance is greater than the distance of 2 diagonally adjacent knots
                {
                    if (dx>0) rope[j].x++; // If previous is larger in x-dir.
                    else if (dx<0) rope[j].x--; // If previous is smaller in x-dir.
                    
                    if (dy>0) rope[j].y++; // If previous is larger in y-dir.
                    else if (dy<0) rope[j].y--; // If previous is smaller in x-dir.
                    
                    if (j == knots-1) // If knot is the last one, store position
                    {
                        snprintf(buffer, bufferSize, "%d:%d", rope[j].x, rope[j].y);
                        visited.insert({string(buffer), true});
                    }
                }
            }
        }
    }
    cout << "Number of visited nodes (Part " << part << "): " << visited.size() << endl;
}

int main()
{   // Generating results for both part 1 and part 2
    for (int k=1; k<=2; k++)
    {
        if (k==1)
        {
            const int knots=2;
            day9(knots, k);
        }
        else
        {
            const int knots=10;
            day9(knots, k);
        }
    }
    return 0;
}
