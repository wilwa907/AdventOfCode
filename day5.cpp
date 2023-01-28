//  To compile, use: g++ -std=c++11 -o play main.cpp -lncurses
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

string row, amount, from, to;
int amountMove, fromMove, toMove;
vector<stack<char>> stacks;

string getTopCrates(vector<stack<char>>) // Function that finds the top crates after all commands ar executed
{
    string topCrates;
    for (int i=0; i<9; i++)
    {
        topCrates.append(1, stacks[i].top());
    }
    
    return topCrates;
}

void partOne()
{
    int LinesInFile=0;
    ifstream infile;
    infile.open("input.txt"); // Open file
    
    while (getline(infile, row)) // Keep reading until end-of-file
    {
        LinesInFile++;
    }
    infile.close();
    
    infile.open("input.txt"); // Re-open file
    for (int i=1; i<=LinesInFile; i++)
    {
        getline(infile, row);
        cout << row << endl;
        if (i>10)
        {   // Finding the important information from each row
            amount = row.at(5);
            if (row.at(6)!=' ')
            {
                amount.push_back(row.at(6));
                from = row.at(13);
                to = row.at(18);
            }
            else
            {
                from = row.at(12);
                to = row.at(17);
            }
            istringstream(amount) >> amountMove; // String to int
            istringstream(from) >> fromMove;
            istringstream(to) >> toMove;
            fromMove = fromMove-1; // Decrease variable with 1 to fit the indexing of the stacks
            toMove = toMove-1;
            cout << amountMove << endl;
            cout << fromMove << endl;
            cout << toMove << endl;
            
            for (int j=1; j<=amountMove; j++)
            {
                char topCrate = stacks[fromMove].top(); // Pick top crate from correct stack
                cout << topCrate << endl;
                stacks[toMove].push(topCrate); // Move crate to right stack
                stacks[fromMove].pop(); // Delete the crate from previous stack
            }
        }
    }
    cout << "The top crates for part one is: " << getTopCrates(stacks) << endl;
}

void partTwo()
{
    int LinesInFile=0;
    ifstream infile;
    infile.open("day5.txt"); // Open file
    
    while (getline(infile, row)) // Keep reading until end-of-file
    {
        LinesInFile++;
    }
    infile.close();
    
    infile.open("day5.txt"); // Re-open file
    for (int i=1; i<=LinesInFile; i++)
    {
        getline(infile, row);
        cout << row << endl;
        if (i>10)
        {   // Finding the important information from each row
            amount = row.at(5);
            if (row.at(6)!=' ')
            {
                amount.push_back(row.at(6));
                from = row.at(13);
                to = row.at(18);
            }
            else
            {
                from = row.at(12);
                to = row.at(17);
            }
            istringstream(amount) >> amountMove; // String to int
            istringstream(from) >> fromMove;
            istringstream(to) >> toMove;
            fromMove = fromMove-1; // Decrease variable with 1 to fit the indexing of the stacks
            toMove = toMove-1;
            cout << amountMove << endl;
            cout << fromMove << endl;
            cout << toMove << endl;
            
            stack<char> tempStack;
            
            for (int j=1; j<=amountMove; j++)
            {
                char topCrate = stacks[fromMove].top(); // Pick top crate from correct stack
                cout << topCrate << endl;
                tempStack.push(topCrate); // Put crates in temporary stack
                stacks[fromMove].pop(); // Delete the crate from previous stack
            }
            while (!tempStack.empty())
            {
                char tempTopCrate = tempStack.top();
                stacks[toMove].push(tempTopCrate);
                tempStack.pop(); // Delete top crate from temporary placeholder
            }
        }
    }
    cout << "The top crates for part two is: " << getTopCrates(stacks) << endl;
}

int main()
{   // Creates all stacks
    stack<char> column1;
    column1.push('H');
    column1.push('R');
    column1.push('B');
    column1.push('D');
    column1.push('Z');
    column1.push('F');
    column1.push('L');
    column1.push('S');
    stack<char> column2;
    column2.push('T');
    column2.push('B');
    column2.push('M');
    column2.push('Z');
    column2.push('R');
    stack<char> column3;
    column3.push('Z');
    column3.push('L');
    column3.push('C');
    column3.push('H');
    column3.push('N');
    column3.push('S');
    stack<char> column4;
    column4.push('S');
    column4.push('C');
    column4.push('F');
    column4.push('J');
    stack<char> column5;
    column5.push('P');
    column5.push('G');
    column5.push('H');
    column5.push('W');
    column5.push('R');
    column5.push('Z');
    column5.push('B');
    stack<char> column6;
    column6.push('V');
    column6.push('J');
    column6.push('Z');
    column6.push('G');
    column6.push('D');
    column6.push('N');
    column6.push('M');
    column6.push('T');
    stack<char> column7;
    column7.push('G');
    column7.push('L');
    column7.push('N');
    column7.push('W');
    column7.push('F');
    column7.push('S');
    column7.push('P');
    column7.push('Q');
    stack<char> column8;
    column8.push('M');
    column8.push('Z');
    column8.push('R');
    stack<char> column9;
    column9.push('M');
    column9.push('C');
    column9.push('L');
    column9.push('G');
    column9.push('V');
    column9.push('R');
    column9.push('T');
     
    stacks = {column1, column2, column3, column4, column5, column6, column7, column8, column9};
    partOne();
    
    stacks = {column1, column2, column3, column4, column5, column6, column7, column8, column9};
    partTwo();
    return 0;
    
}
