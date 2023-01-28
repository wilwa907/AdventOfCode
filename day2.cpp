//
//  main.cpp
//  AoC_day2
//
//  Created by William Wärn on 2022-12-20.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string opponent, me;
int score;
int linesInFile = 0;
int TotalScore = 0;

int main()
{
    ifstream infile;
    infile.open("day2.txt"); // Open file
    
    while (getline(infile, opponent))
        {
            linesInFile++;
        }
    infile.close();
    
    infile.open("day2.txt"); // Re-open file

    for (int i=1; i<=linesInFile; i++)
    {
        score = 0;
        infile >> opponent;
        infile >> me;
        cout << opponent << me << endl;
        // Determine the score each round
        if (me=="X") // I sholud lose
        {
            //score = score + 1;
            if (opponent=="B") // PAPER
            {
                score = score + 1; // Score for choosing ROCK
                score = score + 0; // Score for lose
            }
            else if (opponent=="A") // ROCK
            {
                score = score + 3; // Score for choosing SCISSORS
                score = score + 0; // Score for lose
            }
            else if (opponent=="C") // SCISSORS
            {
                score = score + 2; // Score for choosing PAPER
                score = score + 0; // Score for lose
            }
        }
        else if (me=="Y") // I shold draw
        {
            //score = score + 2;
            if (opponent=="C") // SCISSORS
            {
                score = score + 3; // Score for choosing SCISSORS
                score = score + 3; // Score for draw
            }
            else if (opponent=="B") // PAPER
            {
                score = score + 2; // Score for choosing PAPER
                score = score + 3; // Score for draw
            }
            else if (opponent=="A") // ROCK
            {
                score = score + 1; // Score for choosing ROCK
                score = score + 3; // Score for draw
            }
        }
        else if (me=="Z") // I should win
        {
            //score = score + 3;
            if (opponent=="A") // ROCK
            {
                score = score + 2; // Score for choosing PAPER
                score = score + 6; // Score for win
            }
            else if (opponent=="C") // SCISSORS
            {
                score = score + 1; // Score for choosing ROCK
                score = score + 6; // Score for win
            }
            else if (opponent=="B") // PAPER
            {
                score = score + 3; // Score for choosing SCISSORS
                score = score + 6; // Score for win
            }
        }
        TotalScore = TotalScore + score;
    }
    cout << "My total score would be: " << TotalScore << " if following the strategy guide." << endl;
   
    return 0;
}
