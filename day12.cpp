#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

string line;
char prevNode;
int long ROWS=0, COLS=0;
vector<char> gridRow;
vector<vector<char>> grid;

// Function to check whether the move is within the grid or not
bool isValidMove(int moveToRow, int moveToCol, int long numberOfRows, int long numberOfCols){
    return (moveToRow < numberOfRows && moveToCol < numberOfCols && moveToRow >= 0 && moveToCol >= 0);
}

int partOne(int long ROWS, int long COLS){
    // Finding the end-node and initialize the height 'z'
    pair<int, int> end;
    for (int i=0; i<ROWS; i++){
        for (int j=0; j<COLS; j++){
            if (grid[i][j] == 'E'){
                end = make_pair(i,j);
                grid[i][j] = 'z';
            }
        }
    }
    
    // Create queue of distance value and coordiantes of nodes
    queue<pair<int, pair<int, int>>> q;
    // Create visited grid and initialize end-node as ture
    vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
    visited[end.first][end.second] = true;

    // Starting from the end-node iterating until finding the start-node
    q.push(make_pair(0, end));
    
    while (!q.empty()){
        int dist = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        if (grid[row][col] == 'S') {
            cout << "Goal found in: " << dist << " steps. (PART ONE)" << endl;
            return 0;
        }
        
        // Possible moves in x and y direction
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int i=0; i<4; i++){
            // Check if move is within grid and not visited before
            if (isValidMove(row + dx[i], col + dy[i], ROWS, COLS) && !visited[row + dx[i]][col + dy[i]]){
                if (grid[row + dx[i]][col + dy[i]] == 'S')
                    prevNode = 'a';
                else
                    prevNode = grid[row + dx[i]][col + dy[i]];
                
                // Check if move is valid due to height restrictions, check is based on backwards checking the grid
                if (grid[row][col] - prevNode <= 1){
                    visited[row + dx[i]][col + dy[i]] = true;
                    q.push(make_pair(dist + 1, make_pair(row + dx[i], col + dy[i])));
                }
            }
        }
    }
    cout << "Not reached!" << endl;
    return 0;
}

int partTwo(int long ROWS, int long COLS){
    // Finding the end-node and initialize the height 'z'
    pair<int, int> end;
    for (int i=0; i<ROWS; i++){
        for (int j=0; j<COLS; j++){
            if (grid[i][j] == 'E'){
                end = make_pair(i,j);
                grid[i][j] = 'z';
            }
        }
    }
    
    // Create queue of distance value and coordiantes of nodes
    queue<pair<int, pair<int, int>>> q;
    // Create visited grid and initialize end-node as ture
    vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));
    visited[end.first][end.second] = true;

    // Starting from the end-node iterating until finding the start-node
    q.push(make_pair(0, end));
    
    while (!q.empty()){
        int dist = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        q.pop();

        if(grid[row][col] == 'a') {
            cout << "Goal found in: " << dist << " steps. (PART TWO)" << endl;
            return 0;
        }
        
        // Possible moves in x and y direction
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        for (int i=0; i<4; i++){
            // Check if move is within grid and not visited before
            if (isValidMove(row + dx[i], col + dy[i], ROWS, COLS) && !visited[row + dx[i]][col + dy[i]]){
                if (grid[row + dx[i]][col + dy[i]] == 'S')
                    prevNode = 'a';
                else
                    prevNode = grid[row + dx[i]][col + dy[i]];
                
                // Check if move is valid due to height restrictions, check is based on backwards checking the grid
                if (grid[row][col] - prevNode <= 1){
                    visited[row + dx[i]][col + dy[i]] = true;
                    q.push(make_pair(dist + 1, make_pair(row + dx[i], col + dy[i])));
                }
            }
        }
    }
    cout << "Not reached!" << endl;
    return 0;
}

int main(){
    for (int i=0; i<2; i++){
        fstream infile;
        infile.open("day12.txt");
        
        // Reading File
        while (!infile.eof()){
            getline(infile, line);
            
            if (line.empty()) // Dealing with last empty line in file
                break;
            
            for (char c : line)
                gridRow.push_back(c);
            grid.push_back(gridRow);
            gridRow.clear();
        }
        
        ROWS = grid.size();
        COLS = grid[0].size();
        
        if (i==0)
            partOne(ROWS, COLS);
        else
            partTwo(ROWS, COLS);
    }
}
