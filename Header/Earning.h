#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "Design.h"
using namespace std;
#ifndef EARN_h
#define EARN_h

void Earning()
{
    ifstream inputfile;
    inputfile.open("Data/History.csv");
    if (!inputfile.is_open())
    {
        return;
    }
    string line;
    getline(inputfile, line);
    // store unique date
    map<string, double> totalEarning;
    while (getline(inputfile, line))
    {
        string foodId, foodName, foodQuantity, foodPrice, date;
        stringstream getTotalEarning(line);

        getline(getTotalEarning, foodId, ',');
        getline(getTotalEarning, foodName, ',');
        getline(getTotalEarning, foodQuantity, ',');
        getline(getTotalEarning, foodPrice, ',');
        getline(getTotalEarning, date, ',');

        double price = stod(foodPrice);
        totalEarning[date] += price;
    }
    setPosition(75, 5);
    cout << YELLOW << "==== Total Earning ====" << endl;
    setPosition(70, 6);
    cout << "----------------------------------" << endl;
    setPosition(70, 7);
    cout << "| Date";
    setPosition(98, 7);
    cout << "Earn |";
    setPosition(70, 8);
    cout << "----------------------------------" << RESET << endl;
    int y = 9;
    for (auto pair : totalEarning)
    {
        setPosition(70, y);
        cout << YELLOW << "| " << RESET << ORANGE << pair.first << RESET;
        setPosition(94, y);
        cout << ORANGE << right << setw(6) << fixed << setprecision(2) << pair.second << " $" << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "----------------------------------" << RESET << endl;
    setPosition(70, y + 2);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}

#endif