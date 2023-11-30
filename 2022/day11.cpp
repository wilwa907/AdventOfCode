#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

string line;
int monkey0=0, monkey1=0, monkey2=0, monkey3=0, monkey4=0, monkey5=0, monkey6=0, monkey7=0;
int lineNumber=0, monkey, newItem, maximumValue1, maximumValue2, monkeyBusiness;
vector<int> monkeys;
vector<int> worry;
vector<vector<int>> worryLevel; // 2D-vector

int MovedItems(int item, int toMonkey, int fromMonkey) // Function that handles the updates of moved items
{
    if (toMonkey>fromMonkey) // Update item only if moved to a monkey later in the queue, otherwise updated next round
    {
        // Monkey 0
        if (toMonkey == 0){
            monkey0++; // Add inspected items
            item = item * 7;
            item = item / 3;}
        // Monkey 1
        else if (toMonkey == 1){
            monkey1++; // Add inspected items
            item = item + 5;
            item = item / 3;}
        // Monkey 2
        else if (toMonkey == 2){
            monkey2++; // Add inspected items
            item = item * item;
            item = item / 3;}
        // Monkey 3
        else if (toMonkey == 3){
            monkey3++; // Add inspected items
            item = item + 6;
            item = item / 3;}
        // Monkey 4
        else if (toMonkey == 4){
            monkey4++; // Add inspected items
            item = item * 11;
            item = item / 3;}
        // Monkey 5
        else if (toMonkey == 5){
            monkey5++; // Add inspected items
            item = item + 8;
            item = item / 3;}
        // Monkey 6
        else if (toMonkey == 6){
            monkey6++; // Add inspected items
            item = item + 1;
            item = item / 3;}
        // Monkey 7
        else if (toMonkey == 7){
            monkey7++; // Add inspected items
            item = item + 4;
            item = item / 3;}
    }
    return item;
}

void day11()
{
    fstream infile;
    infile.open("day11.txt");
    
    while (getline(infile, line))
    {
        if (lineNumber % 7 == 0) // Get monkey
        {
            istringstream(line.substr(6, line.find("\n"))) >> monkey;
            monkeys.push_back(monkey);
        }
        
        else if (lineNumber % 7 == 1) // Get worry levels
        {
            line.erase(0, 18); // Erase first part of line and all ,
            line.erase(remove(line.begin(), line.end(), ','), line.end());
            stringstream ss(line);
            int worryInt;
            worry.clear();
            while(ss >> worryInt)
                worry.push_back(worryInt);
            worryLevel.push_back(worry);
        }
        // Monkey 0
        else if (lineNumber % 7 == 2 && monkeys.size() == 1) // Gets the initial 2D-vector after inspection
            for (int i=0; i<worryLevel[0].size(); i++){
                monkey0++; 
                worryLevel[0][i] = worryLevel[0][i] * 7;
                worryLevel[0][i] = worryLevel[0][i] / 3;}
        // Monkey 1
        else if (lineNumber % 7 == 2 && monkeys.size() == 2)
            for (int i=0; i<worryLevel[1].size(); i++){
                monkey1++;
                worryLevel[1][i] = worryLevel[1][i] + 5;
                worryLevel[1][i] = worryLevel[1][i] / 3;}
        // Monkey 2
        else if (lineNumber % 7 == 2 && monkeys.size() == 3)
            for (int i=0; i<worryLevel[2].size(); i++){
                monkey2++;
                worryLevel[2][i] = worryLevel[2][i] * worryLevel[2][i];
                worryLevel[2][i] = worryLevel[2][i] / 3;}
        // Monkey 3
        else if (lineNumber % 7 == 2 && monkeys.size() == 4)
            for (int i=0; i<worryLevel[3].size(); i++){
                monkey3++;
                worryLevel[3][i] = worryLevel[3][i] + 6;
                worryLevel[3][i] = worryLevel[3][i] / 3;}
        // Monkey 4
        else if (lineNumber % 7 == 2 && monkeys.size() == 5)
            for (int i=0; i<worryLevel[4].size(); i++){
                monkey4++;
                worryLevel[4][i] = worryLevel[4][i] * 11;
                worryLevel[4][i] = worryLevel[4][i] / 3;}
        // Monkey 5
        else if (lineNumber % 7 == 2 && monkeys.size() == 6)
            for (int i=0; i<worryLevel[5].size(); i++){
                monkey5++;
                worryLevel[5][i] = worryLevel[5][i] + 8;
                worryLevel[5][i] = worryLevel[5][i] / 3;}
        // Monkey 6
        else if (lineNumber % 7 == 2 && monkeys.size() == 7)
            for (int i=0; i<worryLevel[6].size(); i++){
                monkey6++;
                worryLevel[6][i] = worryLevel[6][i] + 1;
                worryLevel[6][i] = worryLevel[6][i] / 3;}
        // Monkey 7
        else if (lineNumber % 7 == 2 && monkeys.size() == 8)
            for (int i=0; i<worryLevel[7].size(); i++){
                monkey7++;
                worryLevel[7][i] = worryLevel[7][i] + 4;
                worryLevel[7][i] = worryLevel[7][i] / 3;}
        lineNumber++; // Variable to keep track of reading file
    }
   
    // Print
    for (int i=0; i<worryLevel.size(); i++)
    {
       for (int j=0; j<worryLevel[i].size(); j++)
           cout << worryLevel[i][j] << " ";
       cout << endl;
    }
    
    // Throwing monkey 0:s items
    for (int i=0; i<worryLevel[0].size(); i++) // Looping through monkey 0:s items
    {
        newItem=0;
        if (worryLevel[0][i] % 3 == 0){
            newItem = MovedItems(worryLevel[0][i], 4, 0); // Function thats checks which monkey the item is moved to and if an update is needed
            worryLevel[4].push_back(newItem);} // Append new value
        else{
            newItem = MovedItems(worryLevel[0][i], 1, 0);
            worryLevel[1].push_back(newItem);}
    }
    worryLevel[0].clear(); // Clear monkey 0:s items since all is thrown
    
    // Throwing monkey 1:s items
    for (int i=0; i<worryLevel[1].size(); i++)
    {
        newItem=0;
        if (worryLevel[1][i] % 13 == 0){
            newItem = MovedItems(worryLevel[1][i], 7, 1);
            worryLevel[7].push_back(newItem);}
        else{
            newItem = MovedItems(worryLevel[1][i], 3, 1);
            worryLevel[3].push_back(newItem);}
    }
    worryLevel[1].clear();

    // Throwing monkey 2:s items
    for (int i=0; i<worryLevel[2].size(); i++)
    {
        newItem=0;
        if (worryLevel[2][i] % 2 == 0){
            newItem = MovedItems(worryLevel[2][i], 6, 2);
            worryLevel[6].push_back(newItem);}
        else{
            newItem = MovedItems(worryLevel[2][i], 5, 2);
            worryLevel[5].push_back(newItem);}
    }
    worryLevel[2].clear();
    
    // Throwing monkey 3:s items
    for (int i=0; i<worryLevel[3].size(); i++)
    {
        newItem=0;
        if (worryLevel[3][i] % 11 == 0){
            newItem = MovedItems(worryLevel[3][i], 2, 3);
            worryLevel[2].push_back(newItem);}
        else{
            newItem = MovedItems(worryLevel[3][i], 6, 3);
            worryLevel[6].push_back(newItem);}
    }
    worryLevel[3].clear();
    
    // Throwing monkey 4:s items
    for (int i=0; i<worryLevel[4].size(); i++)
    {
        newItem=0;
        if (worryLevel[4][i] % 5 == 0){
            newItem = MovedItems(worryLevel[4][i], 1, 4);
            worryLevel[1].push_back(newItem);}
        else{
            newItem = MovedItems(worryLevel[4][i], 7, 4);
            worryLevel[7].push_back(newItem);}
    }
    worryLevel[4].clear();
    
    // Throwing monkey 5:s items
    for (int i=0; i<worryLevel[5].size(); i++)
    {
        if (worryLevel[5][i] % 17 == 0){
            newItem = MovedItems(worryLevel[5][i], 4, 5);
            worryLevel[4].push_back(newItem);}
        else{
            newItem = MovedItems(worryLevel[5][i], 0, 5);
            worryLevel[0].push_back(newItem);}
    }
    worryLevel[5].clear();
    
    // Throwing monkey 6:s items
    for (int i=0; i<worryLevel[6].size(); i++)
    {
        if (worryLevel[6][i] % 19 == 0){
            newItem = MovedItems(worryLevel[6][i], 0, 6);
            worryLevel[0].push_back(newItem);}
        else{
            newItem = MovedItems(worryLevel[6][i], 5, 6);
            worryLevel[5].push_back(newItem);}
    }
    worryLevel[6].clear();
    
    // Throwing monkey 7:s items
    for (int i=0; i<worryLevel[7].size(); i++)
    {
        if (worryLevel[7][i] % 7 == 0){
            newItem = MovedItems(worryLevel[7][i], 3, 7);
            worryLevel[3].push_back(newItem);}
        else{
            newItem = MovedItems(worryLevel[7][i], 2, 7);
            worryLevel[2].push_back(newItem);}
    }
    worryLevel[7].clear();
    
    for (int k=1; k<20; k++) // 20 rounds (1 + 19)
    {
        // Monkey 0
        for (int i=0; i<worryLevel[0].size(); i++){
            monkey0++;
            worryLevel[0][i] = worryLevel[0][i] * 7;
            worryLevel[0][i] = worryLevel[0][i] / 3;}
        // Monkey 1
        for (int i=0; i<worryLevel[1].size(); i++){
            monkey1++;
            worryLevel[1][i] = worryLevel[1][i] + 5;
            worryLevel[1][i] = worryLevel[1][i] / 3;}
        // Monkey 2
        for (int i=0; i<worryLevel[2].size(); i++){
            monkey2++;
            worryLevel[2][i] = worryLevel[2][i] * worryLevel[2][i];
            worryLevel[2][i] = worryLevel[2][i] / 3;}
        // Monkey 3
        for (int i=0; i<worryLevel[3].size(); i++){
            monkey3++;
            worryLevel[3][i] = worryLevel[3][i] + 6;
            worryLevel[3][i] = worryLevel[3][i] / 3;}
        // Monkey 4
        for (int i=0; i<worryLevel[4].size(); i++){
            monkey4++;
            worryLevel[4][i] = worryLevel[4][i] * 11;
            worryLevel[4][i] = worryLevel[4][i] / 3;}
        // Monkey 5
        for (int i=0; i<worryLevel[5].size(); i++){
            monkey5++;
            worryLevel[5][i] = worryLevel[5][i] + 8;
            worryLevel[5][i] = worryLevel[5][i] / 3;}
        // Monkey 6
        for (int i=0; i<worryLevel[6].size(); i++){
            monkey6++;
            worryLevel[6][i] = worryLevel[6][i] + 1;
            worryLevel[6][i] = worryLevel[6][i] / 3;}
        // Monkey 7
        for (int i=0; i<worryLevel[7].size(); i++){
            monkey7++;
            worryLevel[7][i] = worryLevel[7][i] + 4;
            worryLevel[7][i] = worryLevel[7][i] / 3;}
        
        // Throwing monkey 0:s items
        for (int i=0; i<worryLevel[0].size(); i++)
        {
            newItem=0;
            if (worryLevel[0][i] % 3 == 0){
                newItem = MovedItems(worryLevel[0][i], 4, 0);
                worryLevel[4].push_back(newItem);}
            else{
                newItem = MovedItems(worryLevel[0][i], 1, 0);
                worryLevel[1].push_back(newItem);}
        }
        worryLevel[0].clear();
        
        // Throwing monkey 1:s items
        for (int i=0; i<worryLevel[1].size(); i++)
        {
            newItem=0;
            if (worryLevel[1][i] % 13 == 0){
                newItem = MovedItems(worryLevel[1][i], 7, 1);
                worryLevel[7].push_back(newItem);}
            else{
                newItem = MovedItems(worryLevel[1][i], 3, 1);
                worryLevel[3].push_back(newItem);}
        }
        worryLevel[1].clear();

        // Throwing monkey 2:s items
        for (int i=0; i<worryLevel[2].size(); i++)
        {
            newItem=0;
            if (worryLevel[2][i] % 2 == 0){
                newItem = MovedItems(worryLevel[2][i], 6, 2);
                worryLevel[6].push_back(newItem);}
            else{
                newItem = MovedItems(worryLevel[2][i], 5, 2);
                worryLevel[5].push_back(newItem);}
        }
        worryLevel[2].clear();
        
        // Throwing monkey 3:s items
        for (int i=0; i<worryLevel[3].size(); i++)
        {
            newItem=0;
            if (worryLevel[3][i] % 11 == 0){
                newItem = MovedItems(worryLevel[3][i], 2, 3);
                worryLevel[2].push_back(newItem);}
            else{
                newItem = MovedItems(worryLevel[3][i], 6, 3);
                worryLevel[6].push_back(newItem);}
        }
        worryLevel[3].clear();
        
        // Throwing monkey 4:s items
        for (int i=0; i<worryLevel[4].size(); i++)
        {
            newItem=0;
            if (worryLevel[4][i] % 5 == 0){
                newItem = MovedItems(worryLevel[4][i], 1, 4);
                worryLevel[1].push_back(newItem);}
            else{
                newItem = MovedItems(worryLevel[4][i], 7, 4);
                worryLevel[7].push_back(newItem);}
        }
        worryLevel[4].clear();
        
        // Throwing monkey 5:s items
        for (int i=0; i<worryLevel[5].size(); i++)
        {
            if (worryLevel[5][i] % 17 == 0){
                newItem = MovedItems(worryLevel[5][i], 4, 5);
                worryLevel[4].push_back(newItem);}
            else{
                newItem = MovedItems(worryLevel[5][i], 0, 5);
                worryLevel[0].push_back(newItem);}
        }
        worryLevel[5].clear();
        
        // Throwing monkey 6:s items
        for (int i=0; i<worryLevel[6].size(); i++)
        {
            if (worryLevel[6][i] % 19 == 0){
                newItem = MovedItems(worryLevel[6][i], 0, 6);
                worryLevel[0].push_back(newItem);}
            else{
                newItem = MovedItems(worryLevel[6][i], 5, 6);
                worryLevel[5].push_back(newItem);}
        }
        worryLevel[6].clear();
        
        // Throwing monkey 7:s items
        for (int i=0; i<worryLevel[7].size(); i++)
        {
            if (worryLevel[7][i] % 7 == 0){
                newItem = MovedItems(worryLevel[7][i], 3, 7);
                worryLevel[3].push_back(newItem);}
            else{
                newItem = MovedItems(worryLevel[7][i], 2, 7);
                worryLevel[2].push_back(newItem);}
        }
        worryLevel[7].clear();
    }
    
    cout << "Monkey 0: " << monkey0 << endl;
    cout << "Monkey 1: " << monkey1 << endl;
    cout << "Monkey 2: " << monkey2 << endl;
    cout << "Monkey 3: " << monkey3 << endl;
    cout << "Monkey 4: " << monkey4 << endl;
    cout << "Monkey 5: " << monkey5 << endl;
    cout << "Monkey 6: " << monkey6 << endl;
    cout << "Monkey 7: " << monkey7 << endl;
    vector<int> numberOfThrows{monkey0, monkey1, monkey2, monkey3, monkey4, monkey5, monkey6, monkey7}; // Vector of total throws
    
    maximumValue1 = *max_element(numberOfThrows.begin(), numberOfThrows.end());
    numberOfThrows.erase(remove(numberOfThrows.begin(), numberOfThrows.end(), maximumValue1), numberOfThrows.end());
    maximumValue2 = *max_element(numberOfThrows.begin(), numberOfThrows.end());
    cout << maximumValue1 << endl;
    cout << maximumValue2 << endl;
    monkeyBusiness = maximumValue1*maximumValue2;
    cout << monkeyBusiness << endl;
}

int main()
{
    day11();
    return 0;
}
