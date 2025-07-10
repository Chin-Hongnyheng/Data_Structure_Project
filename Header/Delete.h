#include <iostream>
#include <fstream>
#include <sstream>
#include "Design.h"
#include <vector>
#ifndef DELETE_h
#define DELETE_h

void DeleteInSingleSet()
{
    ifstream inputfile;
    inputfile.open("Data/SingleSet.csv");
    if (!inputfile.is_open())
    {
        return;
    }

    vector<Food> dishes;
    string line;
    getline(inputfile, line);

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
    while (getline(inputfile, line))
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
    inputfile.close();

    int dishesId;
    bool found = false;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Enter a dishes ID: " << RESET;
        cin >> dishesId;
        for (int i = 0; i < dishes.size(); i++)
        {
            if (dishes[i].id == dishesId)
            {
                // erase() receive only iterator not index or object
                found = true;
                dishes.erase(dishes.begin() + i);
                break;
            }
        }
        if (!found)
        {
            setPosition(70, y + 3);
            cout << RED << "NO ID Found" << RESET << endl;
            y = y + 2;
            continue;
        }
        else
        {
            break;
        }
    }
    setPosition(70, y + 3);
    cout << YELLOW << "PRESS 1 to Confirm Deleting OR PRESS 0 to Cancel Deleting: " << RESET;
    int confirm;
    cin >> confirm;
    if (confirm == 1)
    {
        ofstream outputfile;
        outputfile.open("Data/SingleSet.csv", ios::trunc);
        if (!outputfile.is_open())
        {
            setPosition(70, y + 7);
            cout << RED << "File cannot be Opened" << RESET << endl;
        }
        else
        {
            outputfile << "ID,Name,Price\n";
            for (Food food : dishes)
            {
                outputfile << food.id << ',' << food.name << ',' << fixed << setprecision(2) << food.price << endl;
            }
            outputfile.close();
            setPosition(70, y + 4);
            cout << GREEN << "Dish Deleted Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, y + 6);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}

void DeleteInSignature()
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
    file.close();

    int dishesId;
    bool found = false;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Enter a dishes ID: " << RESET;
        cin >> dishesId;
        for (int i = 0; i < dishes.size(); i++)
        {
            if (dishes[i].id == dishesId)
            {
                // erase() receive only iterator not index or object
                found = true;
                dishes.erase(dishes.begin() + i);
                break;
            }
        }
        if (!found)
        {
            setPosition(70, y + 3);
            cout << RED << "NO ID Found" << RESET << endl;
            y = y + 2;
            continue;
        }
        else
        {
            break;
        }
    }
    setPosition(70, y + 3);
    cout << YELLOW << "PRESS 1 to Confirm Deleting OR PRESS 0 to Cancel Deleting: " << RESET;
    int confirm;
    cin >> confirm;
    if (confirm == 1)
    {
        ofstream outputfile;
        outputfile.open("Data/SignatureFood.csv", ios::trunc);
        if (!outputfile.is_open())
        {
            setPosition(70, y + 7);
            cout << RED << "File cannot be Opened" << RESET << endl;
        }
        else
        {
            outputfile << "ID,Name,Price\n";
            for (Food food : dishes)
            {
                outputfile << food.id << ',' << food.name << ',' << fixed << setprecision(2) << food.price << endl;
            }
            outputfile.close();
            setPosition(70, y + 4);
            cout << GREEN << "Dish Deleted Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, y + 6);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}

void DeleteInFried()
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
    file.close();

    int dishesId;
    bool found = false;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Enter a dishes ID: " << RESET;
        cin >> dishesId;
        for (int i = 0; i < dishes.size(); i++)
        {
            if (dishes[i].id == dishesId)
            {
                // erase() receive only iterator not index or object
                found = true;
                dishes.erase(dishes.begin() + i);
                break;
            }
        }
        if (!found)
        {
            setPosition(70, y + 3);
            cout << RED << "NO ID Found" << RESET << endl;
            y = y + 2;
            continue;
        }
        else
        {
            break;
        }
    }
    setPosition(70, y + 3);
    cout << YELLOW << "PRESS 1 to Confirm Deleting OR PRESS 0 to Cancel Deleting: " << RESET;
    int confirm;
    cin >> confirm;
    if (confirm == 1)
    {
        ofstream outputfile;
        outputfile.open("Data/Fried.csv", ios::trunc);
        if (!outputfile.is_open())
        {
            setPosition(70, y + 7);
            cout << RED << "File cannot be Opened" << RESET << endl;
        }
        else
        {
            outputfile << "ID,Name,Price\n";
            for (Food food : dishes)
            {
                outputfile << food.id << ',' << food.name << ',' << fixed << setprecision(2) << food.price << endl;
            }
            outputfile.close();
            setPosition(70, y + 4);
            cout << GREEN << "Dish Deleted Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, y + 6);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}

void DeleteInAppetizer()
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
    file.close();

    int dishesId;
    bool found = false;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Enter a dishes ID: " << RESET;
        cin >> dishesId;
        for (int i = 0; i < dishes.size(); i++)
        {
            if (dishes[i].id == dishesId)
            {
                // erase() receive only iterator not index or object
                found = true;
                dishes.erase(dishes.begin() + i);
                break;
            }
        }
        if (!found)
        {
            setPosition(70, y + 3);
            cout << RED << "NO ID Found" << RESET << endl;
            y = y + 2;
            continue;
        }
        else
        {
            break;
        }
    }
    setPosition(70, y + 3);
    cout << YELLOW << "PRESS 1 to Confirm Deleting OR PRESS 0 to Cancel Deleting: " << RESET;
    int confirm;
    cin >> confirm;
    if (confirm == 1)
    {
        ofstream outputfile;
        outputfile.open("Data/Fried.csv", ios::trunc);
        if (!outputfile.is_open())
        {
            setPosition(70, y + 7);
            cout << RED << "File cannot be Opened" << RESET << endl;
        }
        else
        {
            outputfile << "ID,Name,Price\n";
            for (Food food : dishes)
            {
                outputfile << food.id << ',' << food.name << ',' << fixed << setprecision(2) << food.price << endl;
            }
            outputfile.close();
            setPosition(70, y + 4);
            cout << GREEN << "Dish Deleted Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, y + 6);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}

void DeleteInExtraMeat()
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
        setPosition(80, y);
        cout << ORANGE << name << RESET;
        setPosition(123, y);
        cout << ORANGE << right << setw(6) << fixed << setprecision(2) << price << " $" << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "---------------------------------------------------------------" << RESET << endl;
    file.close();

    int dishesId;
    bool found = false;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Enter a dishes ID: " << RESET;
        cin >> dishesId;
        for (int i = 0; i < dishes.size(); i++)
        {
            if (dishes[i].id == dishesId)
            {
                // erase() receive only iterator not index or object
                found = true;
                dishes.erase(dishes.begin() + i);
                break;
            }
        }
        if (!found)
        {
            setPosition(70, y + 3);
            cout << RED << "NO ID Found" << RESET << endl;
            y = y + 2;
            continue;
        }
        else
        {
            break;
        }
    }
    setPosition(70, y + 3);
    cout << YELLOW << "PRESS 1 to Confirm Deleting OR PRESS 0 to Cancel Deleting: " << RESET;
    int confirm;
    cin >> confirm;
    if (confirm == 1)
    {
        ofstream outputfile;
        outputfile.open("Data/Fried.csv", ios::trunc);
        if (!outputfile.is_open())
        {
            setPosition(70, y + 7);
            cout << RED << "File cannot be Opened" << RESET << endl;
        }
        else
        {
            outputfile << "ID,Name,Price\n";
            for (Food food : dishes)
            {
                outputfile << food.id << ',' << food.name << ',' << fixed << setprecision(2) << food.price << endl;
            }
            outputfile.close();
            setPosition(70, y + 4);
            cout << GREEN << "Dish Deleted Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, y + 6);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}

void DeleteInCombo()
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
    file.close();

    int dishesId;
    bool found = false;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Enter a dishes ID: " << RESET;
        cin >> dishesId;
        for (int i = 0; i < dishes.size(); i++)
        {
            if (dishes[i].id == dishesId)
            {
                // erase() receive only iterator not index or object
                found = true;
                dishes.erase(dishes.begin() + i);
                break;
            }
        }
        if (!found)
        {
            setPosition(70, y + 3);
            cout << RED << "NO ID Found" << RESET << endl;
            y = y + 2;
            continue;
        }
        else
        {
            break;
        }
    }
    setPosition(70, y + 3);
    cout << YELLOW << "PRESS 1 to Confirm Deleting OR PRESS 0 to Cancel Deleting: " << RESET;
    int confirm;
    cin >> confirm;
    if (confirm == 1)
    {
        ofstream outputfile;
        outputfile.open("Data/Fried.csv", ios::trunc);
        if (!outputfile.is_open())
        {
            setPosition(70, y + 7);
            cout << RED << "File cannot be Opened" << RESET << endl;
        }
        else
        {
            outputfile << "ID,Name,Price\n";
            for (Food food : dishes)
            {
                outputfile << food.id << ',' << food.name << ',' << fixed << setprecision(2) << food.price << endl;
            }
            outputfile.close();
            setPosition(70, y + 4);
            cout << GREEN << "Dish Deleted Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, y + 6);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}
#endif