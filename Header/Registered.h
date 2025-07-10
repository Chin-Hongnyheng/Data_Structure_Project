#include <iostream>
#include <fstream>
#include <sstream>
#include "Design.h"
using namespace std;
#ifndef REGISTERED_h
#define REGISTERED_h
void displayRegistered()
{
    ifstream input;
    input.open("Data/Customer.csv");
    if (!input.is_open())
    {
        return;
    }
    string line;
    getline(input, line);
    setPosition(96, 5);
    cout << YELLOW << "==== User ====" << endl;
    setPosition(70, 6);
    cout << "----------------------------------------------------------------------" << endl;
    setPosition(70, 7);
    cout << "| UserName";
    setPosition(90, 7);
    cout << "Email";
    setPosition(105, 7);
    cout << "Age";
    setPosition(115, 7);
    cout << "Gender";
    setPosition(130, 7);
    cout << "Password |";
    setPosition(70, 8);
    cout << "----------------------------------------------------------------------" << RESET << endl;
    int y = 9;
    while (getline(input, line))
    {
        string userName, Age, Email, Gender, Password;
        stringstream ss(line);

        getline(ss, userName, ',');
        getline(ss, Email, ',');
        getline(ss, Age, ',');
        getline(ss, Gender, ',');
        getline(ss, Password, ',');
        setPosition(70, y);
        cout << YELLOW << "| " << RESET;
        setPosition(74, y);
        cout << ORANGE << userName << RESET;
        setPosition(85, y);
        cout << ORANGE << Email << RESET;
        setPosition(106, y);
        cout << ORANGE << Age << RESET;
        setPosition(118, y);
        cout << ORANGE << Gender << RESET;
        setPosition(123, y);
        cout << ORANGE << fixed << right << setw(15) << Password << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "----------------------------------------------------------------------" << RESET << endl;
    input.close();
    setPosition(70, y + 2);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}
#endif