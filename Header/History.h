#include <iostream>
#include <sstream>
#include <fstream>
#include "Design.h"
#ifndef HISTORY_h
#define HISTORY_h

void History()
{
    ifstream input;
    input.open("Data/History.csv");
    if (!input.is_open())
    {
        return;
    }
    string line;
    getline(input, line);
    setPosition(90, 5);
    cout << YELLOW << "==== Sales History ====" << endl;
    setPosition(70, 6);
    cout << "---------------------------------------------------------------" << endl;
    setPosition(70, 7);
    cout << "| ID";
    setPosition(90, 7);
    cout << "Name";
    setPosition(111, 7);
    cout << "Quantity";
    setPosition(125, 7);
    cout << "Price  |";
    setPosition(70, 8);
    cout << "---------------------------------------------------------------" << RESET << endl;
    int y = 9;
    while (getline(input, line))
    {
        string foodId, foodName, foodQuantity, foodPrice;
        stringstream ss(line);

        getline(ss, foodId, ',');
        getline(ss, foodName, ',');
        getline(ss, foodQuantity, ',');
        getline(ss, foodPrice, ',');
        int id = stoi(foodId);
        double price = stod(foodPrice);
        int quantity = stoi(foodQuantity);
        setPosition(70, y);
        cout << YELLOW << "| " << RESET << ORANGE << id << RESET;
        setPosition(80, y);
        cout << ORANGE << foodName << RESET;
        setPosition(115, y);
        cout << ORANGE << quantity << RESET;
        setPosition(123, y);
        cout << ORANGE << right << setw(6) << fixed << setprecision(2) << price << " $" << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "---------------------------------------------------------------" << RESET << endl;
    input.close();
    setPosition(70, y + 2);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}
#endif