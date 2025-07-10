#include <iostream>
#include "Design.h"
#include <sstream>
#include <fstream>
#include <vector>
#ifndef ADD_H
#define ADD_H

void AddInSingleSet()
{
    ifstream file;
    file.open("Data/SingleSet.csv");
    if (!file.is_open())
    {
        return;
    }

    vector<Food> dishes;
    string line;
    getline(file, line);

    setPosition(81, 5);
    cout << YELLOW << "==== Single Set Menu ====" << endl;
    setPosition(70, 6);
    cout << "------------------------------------------------" << endl;
    setPosition(70, 7);
    cout << "| ID";
    setPosition(90, 7);
    cout << "Name";
    setPosition(111, 7);
    cout << "Price |";
    setPosition(70, 8);
    cout << "------------------------------------------------" << RESET << endl;

    int y = 9;
    while (getline(file, line))
    {
        stringstream ss(line);
        string name, idstr, priceStr;

        getline(ss, idstr, ',');
        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        int id = stoi(idstr);
        double price = stod(priceStr);
        dishes.push_back({id, name, price});
        setPosition(70, y);
        cout << YELLOW << "| " << RESET << ORANGE << id << RESET;
        setPosition(80, y);
        cout << ORANGE << name << RESET;
        setPosition(110, y);
        cout << ORANGE << fixed << setprecision(2) << price << " $" << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "------------------------------------------------" << RESET << endl;

    int newId;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Add your new Dish (ID): " << RESET;
        cin >> newId;
        bool found = false;
        for (Food food : dishes)
        {
            if (newId == food.id)
            {
                setPosition(70, y + 3);
                cout << RED << "This ID already Exist ! Please enter a new one" << RESET << endl;
                y = y + 2;
                found = true;
                continue;
            }
        }
        if (!found)
        {
            y = y + 2;
            break;
        }
    }

    setPosition(70, y + 1);
    cout << YELLOW << "Enter a new Dish name: " << RESET;
    string dishName;
    cin.ignore();
    getline(cin, dishName);
    setPosition(70, y + 2);
    cout << YELLOW << "Enter a Dish Price: " << RESET;
    double dishPrice;
    cin >> dishPrice;
    setPosition(70, y + 4);
    cout << YELLOW << "PRESS 1 to Confirm your ADDING OR PRESS 0 to Cancel your ADDING: ";
    int verify;
    cin >> verify;

    if (verify == 1)
    {
        setPosition(70, y + 6);
        cout << GREEN << "New Dish ADDED!!" << RESET << endl;
        ofstream File;
        File.open("Data/SingleSet.csv", ios::app);
        if (!File.is_open())
        {
            setPosition(70, 5);
            cout << RED << "File Cannot Open!" << RESET << endl;
            return;
        }
        File << newId << ',' << dishName << ',' << dishPrice << endl;
        File.close();
    }
    else if (verify == 0)
    {
        return;
    }
    setPosition(70, y + 8);
    cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
    return;
}

void AddInSignature()
{
    ifstream file;
    file.open("Data/SignatureFood.csv");
    if (!file.is_open())
    {
        return;
    }
    vector<Food> dishes;
    string line;
    getline(file, line);
    setPosition(85, 5);
    cout << YELLOW << "==== Signature Set Menu ====" << endl;
    setPosition(70, 6);
    cout << "----------------------------------------------------------" << endl;
    setPosition(70, 7);
    cout << "| ID";
    setPosition(95, 7);
    cout << "Name";
    setPosition(120, 7);
    cout << "Price  |";
    setPosition(70, 8);
    cout << "----------------------------------------------------------" << RESET << endl;
    int y = 9;

    while (getline(file, line))
    {
        stringstream ss(line);
        string name, idstr, priceStr;

        getline(ss, idstr, ',');
        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        int id = stoi(idstr);
        double price = stod(priceStr);
        dishes.push_back({id, name, price});
        setPosition(70, y);
        cout << YELLOW << "| " << RESET << ORANGE << id << RESET;
        setPosition(80, y);
        cout << ORANGE << name << RESET;
        setPosition(120, y);
        cout << ORANGE << fixed << setprecision(2) << price << " $" << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "----------------------------------------------------------" << RESET << endl;

    int newId;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Add your new Dish (ID): " << RESET;
        cin >> newId;
        bool found = false;
        for (Food food : dishes)
        {
            if (newId == food.id)
            {
                setPosition(70, y + 3);
                cout << RED << "This ID already Exist ! Please enter a new one" << RESET << endl;
                y = y + 2;
                found = true;
                continue;
            }
        }
        if (!found)
        {
            y = y + 2;
            break;
        }
    }

    setPosition(70, y + 1);
    cout << YELLOW << "Enter a new Dish name: " << RESET;
    string dishName;
    cin.ignore();
    getline(cin, dishName);
    setPosition(70, y + 2);
    cout << YELLOW << "Enter a Dish Price: " << RESET;
    double dishPrice;
    cin >> dishPrice;
    setPosition(70, y + 4);
    cout << YELLOW << "PRESS 1 to Confirm your ADDING OR PRESS 0 to Cancel your ADDING: ";
    int verify;
    cin >> verify;

    if (verify == 1)
    {
        setPosition(70, y + 6);
        cout << GREEN << "New Dish ADDED!!" << RESET << endl;
        ofstream File;
        File.open("Data/SignatureFood.csv", ios::app);
        if (!File.is_open())
        {
            setPosition(70, 5);
            cout << RED << "File Cannot Open!" << RESET << endl;
            return;
        }
        File << newId << ',' << dishName << ',' << dishPrice << endl;
        File.close();
    }
    else if (verify == 0)
    {
        return;
    }
    setPosition(70, y + 8);
    cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
    return;
}

void AddInFried()
{
    ifstream file;
    file.open("Data/Fried.csv");
    if (!file.is_open())
    {
        return;
    }
    vector<Food> dishes;
    string line;
    getline(file, line);
    setPosition(90, 5);
    cout << YELLOW << "==== Fried Set Menu ====" << endl;
    setPosition(70, 6);
    cout << "---------------------------------------------------------------" << endl;
    setPosition(70, 7);
    cout << "| ID";
    setPosition(95, 7);
    cout << "Name";
    setPosition(125, 7);
    cout << "Price  |";
    setPosition(70, 8);
    cout << "---------------------------------------------------------------" << RESET << endl;

    int y = 9;
    while (getline(file, line))
    {
        stringstream ss(line);
        string name, idstr, priceStr;

        getline(ss, idstr, ',');
        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        int id = stoi(idstr);
        double price = stod(priceStr);
        dishes.push_back({id, name, price});
        setPosition(70, y);
        cout << YELLOW << "| " << RESET << ORANGE << id << RESET;
        setPosition(80, y);
        cout << ORANGE << name << RESET;
        setPosition(123, y);
        cout << ORANGE << right << setw(6) << fixed << setprecision(2) << price << " $" << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "---------------------------------------------------------------" << RESET << endl;

    int newId;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Add your new Dish (ID): " << RESET;
        cin >> newId;
        bool found = false;
        for (Food food : dishes)
        {
            if (newId == food.id)
            {
                setPosition(70, y + 3);
                cout << RED << "This ID already Exist ! Please enter a new one" << RESET << endl;
                y = y + 2;
                found = true;
                continue;
            }
        }
        if (!found)
        {
            y = y + 2;
            break;
        }
    }

    setPosition(70, y + 1);
    cout << YELLOW << "Enter a new Dish name: " << RESET;
    string dishName;
    cin.ignore();
    getline(cin, dishName);
    setPosition(70, y + 2);
    cout << YELLOW << "Enter a Dish Price: " << RESET;
    double dishPrice;
    cin >> dishPrice;
    setPosition(70, y + 4);
    cout << YELLOW << "PRESS 1 to Confirm your ADDING OR PRESS 0 to Cancel your ADDING: ";
    int verify;
    cin >> verify;

    if (verify == 1)
    {
        setPosition(70, y + 6);
        cout << GREEN << "New Dish ADDED!!" << RESET << endl;
        ofstream File;
        File.open("Data/Fried.csv", ios::app);
        if (!File.is_open())
        {
            setPosition(70, 5);
            cout << RED << "File Cannot Open!" << RESET << endl;
            return;
        }
        File << newId << ',' << dishName << ',' << dishPrice << endl;
        File.close();
    }
    else if (verify == 0)
    {
        return;
    }
    setPosition(70, y + 8);
    cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
    return;
}

void AddInAppetizer()
{
    ifstream file;
    file.open("Data/Appetizer.csv");
    if (!file.is_open())
    {
        return;
    }
    vector<Food> dishes;
    string line;
    getline(file, line);
    setPosition(87, 5);
    cout << YELLOW << "==== Appetizer Set Menu ====" << endl;
    setPosition(70, 6);
    cout << "---------------------------------------------------------------" << endl;
    setPosition(70, 7);
    cout << "| ID";
    setPosition(95, 7);
    cout << "Name";
    setPosition(125, 7);
    cout << "Price  |";
    setPosition(70, 8);
    cout << "---------------------------------------------------------------" << RESET << endl;

    int y = 9;
    while (getline(file, line))
    {
        stringstream ss(line);
        string name, idstr, priceStr;

        getline(ss, idstr, ',');
        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        int id = stoi(idstr);
        double price = stod(priceStr);
        dishes.push_back({id, name, price});
        setPosition(70, y);
        cout << YELLOW << "| " << RESET << ORANGE << id << RESET;
        setPosition(80, y);
        cout << ORANGE << name << RESET;
        setPosition(123, y);
        cout << ORANGE << right << setw(6) << fixed << setprecision(2) << price << " $" << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "---------------------------------------------------------------" << RESET << endl;

    int newId;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Add your new Dish (ID): " << RESET;
        cin >> newId;
        bool found = false;
        for (Food food : dishes)
        {
            if (newId == food.id)
            {
                setPosition(70, y + 3);
                cout << RED << "This ID already Exist ! Please enter a new one" << RESET << endl;
                y = y + 2;
                found = true;
                continue;
            }
        }
        if (!found)
        {
            y = y + 2;
            break;
        }
    }

    setPosition(70, y + 1);
    cout << YELLOW << "Enter a new Dish name: " << RESET;
    string dishName;
    cin.ignore();
    getline(cin, dishName);
    setPosition(70, y + 2);
    cout << YELLOW << "Enter a Dish Price: " << RESET;
    double dishPrice;
    cin >> dishPrice;
    setPosition(70, y + 4);
    cout << YELLOW << "PRESS 1 to Confirm your ADDING OR PRESS 0 to Cancel your ADDING: ";
    int verify;
    cin >> verify;

    if (verify == 1)
    {
        setPosition(70, y + 6);
        cout << GREEN << "New Dish ADDED!!" << RESET << endl;
        ofstream File;
        File.open("Data/Appetizer.csv", ios::app);
        if (!File.is_open())
        {
            setPosition(70, 5);
            cout << RED << "File Cannot Open!" << RESET << endl;
            return;
        }
        File << newId << ',' << dishName << ',' << dishPrice << endl;
        File.close();
    }
    else if (verify == 0)
    {
        return;
    }
    setPosition(70, y + 8);
    cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
    return;
}

void AddInCombo()
{
    ifstream file;
    file.open("Data/ComboSet.csv");
    if (!file.is_open())
    {
        return;
    }
    vector<Food> dishes;
    string line;
    getline(file, line);
    setPosition(87, 5);
    cout << YELLOW << "==== Combo Set Menu ====" << endl;
    setPosition(70, 6);
    cout << "---------------------------------------------------------------" << endl;
    setPosition(70, 7);
    cout << "| ID";
    setPosition(95, 7);
    cout << "Name";
    setPosition(125, 7);
    cout << "Price  |";
    setPosition(70, 8);
    cout << "---------------------------------------------------------------" << RESET << endl;

    int y = 9;
    while (getline(file, line))
    {
        stringstream ss(line);
        string name, idstr, priceStr;

        getline(ss, idstr, ',');
        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        int id = stoi(idstr);
        double price = stod(priceStr);
        dishes.push_back({id, name, price});
        setPosition(70, y);
        cout << YELLOW << "| " << RESET << ORANGE << id << RESET;
        setPosition(80, y);
        cout << ORANGE << name << RESET;
        setPosition(123, y);
        cout << ORANGE << right << setw(6) << fixed << setprecision(2) << price << " $" << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "---------------------------------------------------------------" << RESET << endl;

    int newId;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Add your new Dish (ID): " << RESET;
        cin >> newId;
        bool found = false;
        for (Food food : dishes)
        {
            if (newId == food.id)
            {
                setPosition(70, y + 3);
                cout << RED << "This ID already Exist ! Please enter a new one" << RESET << endl;
                y = y + 2;
                found = true;
                continue;
            }
        }
        if (!found)
        {
            y = y + 2;
            break;
        }
    }

    setPosition(70, y + 1);
    cout << YELLOW << "Enter a new Dish name: " << RESET;
    string dishName;
    cin.ignore();
    getline(cin, dishName);
    setPosition(70, y + 2);
    cout << YELLOW << "Enter a Dish Price: " << RESET;
    double dishPrice;
    cin >> dishPrice;
    setPosition(70, y + 4);
    cout << YELLOW << "PRESS 1 to Confirm your ADDING OR PRESS 0 to Cancel your ADDING: ";
    int verify;
    cin >> verify;

    if (verify == 1)
    {
        setPosition(70, y + 6);
        cout << GREEN << "New Dish ADDED!!" << RESET << endl;
        ofstream File;
        File.open("Data/ComboSet.csv", ios::app);
        if (!File.is_open())
        {
            setPosition(70, 5);
            cout << RED << "File Cannot Open!" << RESET << endl;
            return;
        }
        File << newId << ',' << dishName << ',' << dishPrice << endl;
        File.close();
    }
    else if (verify == 0)
    {
        return;
    }
    setPosition(70, y + 8);
    cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
    return;
}

void AddInExtraMeat()
{
    ifstream file;
    file.open("Data/Extra.csv");
    if (!file.is_open())
    {
        return;
    }
    vector<Food> dishes;
    string line;
    getline(file, line);
    setPosition(92, 5);
    cout << YELLOW << "==== Extra Meat ====" << endl;
    setPosition(70, 6);
    cout << "---------------------------------------------------------------" << endl;
    setPosition(70, 7);
    cout << "| ID";
    setPosition(95, 7);
    cout << "Name";
    setPosition(125, 7);
    cout << "Price  |";
    setPosition(70, 8);
    cout << "---------------------------------------------------------------" << RESET << endl;

    int y = 9;
    while (getline(file, line))
    {
        stringstream ss(line);
        string name, idstr, priceStr;

        getline(ss, idstr, ',');
        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        int id = stoi(idstr);
        double price = stod(priceStr);
        dishes.push_back({id, name, price});
        setPosition(70, y);
        cout << YELLOW << "| " << RESET << ORANGE << id << RESET;
        setPosition(90, y);
        cout << ORANGE << name << RESET;
        setPosition(123, y);
        cout << ORANGE << right << setw(6) << fixed << setprecision(2) << price << " $" << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "---------------------------------------------------------------" << RESET << endl;

    int newId;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Add your new Dish (ID): " << RESET;
        cin >> newId;
        bool found = false;
        for (Food food : dishes)
        {
            if (newId == food.id)
            {
                setPosition(70, y + 3);
                cout << RED << "This ID already Exist ! Please enter a new one" << RESET << endl;
                y = y + 2;
                found = true;
                continue;
            }
        }
        if (!found)
        {
            y = y + 2;
            break;
        }
    }

    setPosition(70, y + 1);
    cout << YELLOW << "Enter a new Dish name: " << RESET;
    string dishName;
    cin.ignore();
    getline(cin, dishName);
    setPosition(70, y + 2);
    cout << YELLOW << "Enter a Dish Price: " << RESET;
    double dishPrice;
    cin >> dishPrice;
    setPosition(70, y + 4);
    cout << YELLOW << "PRESS 1 to Confirm your ADDING OR PRESS 0 to Cancel your ADDING: ";
    int verify;
    cin >> verify;

    if (verify == 1)
    {
        setPosition(70, y + 6);
        cout << GREEN << "New Dish ADDED!!" << RESET << endl;
        ofstream File;
        File.open("Data/Extra.csv", ios::app);
        if (!File.is_open())
        {
            setPosition(70, 5);
            cout << RED << "File Cannot Open!" << RESET << endl;
            return;
        }
        File << newId << ',' << dishName << ',' << dishPrice << endl;
        File.close();
    }
    else if (verify == 0)
    {
        return;
    }
    setPosition(70, y + 8);
    cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
    return;
}
#endif