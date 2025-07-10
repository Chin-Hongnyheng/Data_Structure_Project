#include <iostream>
#include <sstream>
#include "Receipt.h"
#include "admin.h"
#include "Design.h"
using namespace std;
#ifndef LOGIN_H
#define LOGIN_H

bool login()
{
    system("cls");
    setPosition(80, 5);
    cout << GREEN << "::: Log in :::" << endl;
    setPosition(80, 7);
    cout << "Enter UserName: " << RESET;
    string name;
    cin >> name;
    setPosition(80, 8);
    cout << GREEN << "Enter a Password: " << RESET;
    string inputPassword;
    inputPassword = getPassword();
    cout << endl;

    cin.clear();

    ifstream File;
    string line;
    File.open("Data/Customer.csv");
    bool found = false;
    if (!File.is_open())
    {
        return false;
    }
    else if (File.is_open())
    {
        getline(File, line);
        while (getline(File, line))
        {
            string username, email, age, gender, password;
            stringstream getString(line);

            getline(getString, username, ',');
            getline(getString, email, ',');
            getline(getString, age, ',');
            getline(getString, gender, ',');
            getline(getString, password, ',');

            if (name == username && inputPassword == password)
            {
                // Global variable from Receipt.h
                Name = username;
                // Global variable for verify admin
                userName = username;
                userPassword = password;
                found = true;
                break;
            }
        }
        if (found)
        {
            setPosition(80, 10);
            cout << GREEN << "Successful Log in" << RESET << endl;
            setPosition(80, 12);
            cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
            cin.ignore();
            cin.get();
            system("cls");
        }
        if (!found)
        {
            setPosition(80, 10);
            cout << RED << "Incorrect Input! Try again" << RESET << endl;
            setPosition(80, 12);
            cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
            cin.ignore();
            cin.get();
            system("cls");
        }
    }
    return found;
}
#endif
