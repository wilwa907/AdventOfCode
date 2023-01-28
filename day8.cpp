#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int visibleTrees=0, lineNumb=0;
string line, lineRow, lineColumn;
vector<int> row;
vector<int> col;
bool leftTrees, rightTrees, upTrees, downTrees;

// Part 2
int bestPos=0, whichLine=0;
vector<int> treesSeen;


void GetColumn(int column) // Function to get the column from input
{
    fstream infile;
    infile.open("day8.txt");
    
    while (getline(infile, lineColumn))
    {
        int columnInt = lineColumn.at(column) - '0';
        col.push_back(columnInt);
    }
    
    for (auto v : col)
    {
        cout << v << endl;
    }
    cout << endl;
}

void CheckFromDown(int currentPos) // Function to check trees under current tree
{
    downTrees = true;
    cout << "Ner-i: " << row[currentPos] << endl;
    for (unsigned long int j = col.size()-1; j > 0; j--) // All ints on col
    {
        cout << "Ner-j: " << col[j] << endl;
        if (lineNumb-1 == j && downTrees) // If comparing with itself and true
        {
            visibleTrees++;
            break;
        }
        if (row[currentPos] <= col[j]) // If a tree under is larger
        {
            downTrees = false;
            break;
        }
        else
            continue;
    }
}

void CheckFromUp(int currentPos) // Function to check trees above current tree
{
    col.clear();
    GetColumn(currentPos);
    upTrees = true;
    cout << "Upp-i: " << row[currentPos] << endl;
    for (unsigned int j = 0; j < col.size(); j++) // All ints on col
    {
        cout << "Upp-j: " << col[j] << endl;
        if (lineNumb-1 == j && upTrees) // If comparing with itself and true
        {
            visibleTrees++;
            break;
        }
        if (row[currentPos] <= col[j]) // If a tree up is larger
        {
            CheckFromDown(currentPos);
            upTrees = false;
            break;
        }
        else
            continue;
    }
}

void CheckFromRight(vector<int> vec, int i, int currentPos) // Function to check trees to the right of current tree
{
    rightTrees = true;
    cout << "Right-i: " << i << endl;
    for (unsigned long int j = row.size()-1; j > 0; j--) // All ints on row
    {
        cout << "Right-j: " << row[j] << endl;
        if (currentPos == j && rightTrees) // If comparing with itself and true
        {
            visibleTrees++;
            break;
        }
        if (i <= row[j]) // If a tree to the right is larger
        {
            CheckFromUp(currentPos);
            rightTrees = false;
            break;
        }
        else
            continue;
    }
}

void CheckFromLeft(vector<int> vec)
{
    for (unsigned int i = 1; i < row.size()-1; i++) // Ints inside of box
    {
        leftTrees = true;
        cout << "Left-i: " << row[i] << endl;
        for (unsigned int j = 0; j < row.size(); j++) // All ints on row
        {
            cout << "Left-j: " << row[j] << endl;
            if (i == j && leftTrees) // If comparing with itself and true
            {
                visibleTrees++;
                break;
            }
            if (row[i] <= row[j]) // If a tree to the left is larger
            {
                CheckFromRight(row, row[i], i);
                leftTrees = false;
                break;
            }
            else
                continue;
        }
    }
}

void GetRow() // Function to get the row from input
{
    fstream infile;
    infile.open("day8.txt");
    
    int check = 0; // Getting a new row each time this function is called and not just first row every time
    getline(infile, lineRow);
    while (check!=lineNumb)
    {
        getline(infile, lineRow);
        check++;
    }

    for (int i=0; i<=lineRow.length()-1; i++)
    {
        if (i==0 || i==lineRow.length()-1) // Get the edge trees for each row
        {
            visibleTrees++;
            int rowInt = lineRow.at(i) - '0';
            row.push_back(rowInt);
        }
        else
        {
            int rowInt = lineRow.at(i) - '0';
            row.push_back(rowInt);
        }
    }
    
    for (auto r : row)
    {
        cout << r << " ";
    }
    cout << endl;
}

int main()
{   // ------PART 1------
    fstream infile;
    infile.open("day8.txt");
    while (getline(infile, line))
    {
        row.clear();
        GetRow();
        lineNumb++;
        
        if (lineNumb==1 || lineNumb==line.length()) // First and last row
        {
            for (int i=1; i<=line.length()-2; i++) // Add all trees, except corner trees, on first and last row
            {
                visibleTrees++;
            }
        }
        else // Else get the lines that we need to check
        {
            CheckFromLeft(row);
        }
    }
    cout << "Part 1 (Visible trees): " << visibleTrees << "st" << endl;
    
    // ------PART 2------
    lineNumb=0;
    fstream infilePart2;
    infilePart2.open("day8.txt");
    while (getline(infilePart2, line))
    {
        lineNumb++;
        if (lineNumb==1 || lineNumb==line.length())
            continue; // Skip first and last row
        else
        {
            whichLine++;
            for (int i = 1; i < line.size()-1; i++) // Ints inside of box
            {
                treesSeen.clear();
                int trees=0;
                cout << "i: " << line.at(i) << endl;
                for (int j=i-1; j>=0; j--) // Checks to left
                {
                    cout << "j left: " << line.at(j) << endl;
                    if (line.at(j)<line.at(i))
                        trees++;
                    else
                    {
                        trees++;
                        break;
                    }
                }
                cout << "Trees left: " << trees << endl;
                treesSeen.push_back(trees); // Append left trees in vector
                trees=0;
                
                for (int j=i+1; j<=line.length()-1; j++) // Checks to right
                {
                    cout << "j right: " << line.at(j) << endl;
                    if (line.at(j)<line.at(i))
                        trees++;
                    else
                    {
                        trees++;
                        break;
                    }
                }
                cout << "Trees right: " << trees << endl;
                treesSeen.push_back(trees); // Append right trees in vector
                trees=0;
                
                col.clear(); // Clear column from part 1 and then for every new row
                GetColumn(i); // Get the column
                for (int j=whichLine-1; j>=0; j--) // Checks above
                {
                    cout << "j up: " << col.at(j) << endl;
                    if (col.at(j)<col.at(whichLine))
                        trees++;
                    else
                    {
                        trees++;
                        break;
                    }
                }
                cout << "Trees Up: " << trees << endl;
                treesSeen.push_back(trees); // Append up trees in vector
                trees=0;
                
                for (int j=whichLine+1; j<=col.size()-1; j++) // Checks below
                {
                    cout << "j down: " << col.at(j) << endl;
                    if (col.at(j)<col.at(whichLine))
                        trees++;
                    else
                    {
                        trees++;
                        break;
                    }
                }
                cout << "Trees Down: " << trees << endl;
                treesSeen.push_back(trees); // Append down trees in vector
                // Multiply all trees in vector and comparing with the current best value
                int multi = 1;
                for (const auto& e: treesSeen)
                    multi *= e;
                if (multi>bestPos)
                    bestPos=multi;
            }
        }
    }
    cout << "Part 2 (Best position): " << bestPos << "st" << endl;
    return 0;
}
