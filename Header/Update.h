#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include "Design.h"
#ifndef UPDATE_H
#define UPDATE_H

void UpdateInSingleSet()
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
    setPosition(67, 3);
    cout << YELLOW << "Type Number 0 to Exit the Program and Cancel this Menu" << RESET << endl;
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
        setPosition(109, y);
        cout << ORANGE << fixed << setprecision(2) << setw(5) << price << " $" << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "------------------------------------------------" << RESET << endl;
    inputfile.close();

    int dishesId;
    string dishesName;
    double dishesPrice;
    bool found = false;
    bool updated = false;
    int idInputLine = y + 2;
    while (!updated)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Enter a dishes ID: " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> dishesId)
            {
                if (dishesId == 0)
                {
                    return;
                }
                for (Food &food : dishes)
                {
                    if (food.id == dishesId)
                    {
                        setPosition(70, y + 2 + line);
                        cout << YELLOW << "Enter new Dish Name: " << RESET;
                        line++;
                        cin.ignore();
                        getline(cin, dishesName);
                        if (dishesName == "0")
                        {
                            return;
                        }
                        while (true)
                        {
                            setPosition(70, y + 2 + line);
                            cout << YELLOW << "Enter a Dish Price: " << RESET;
                            line++;
                            if (cin >> dishesPrice)
                            {
                                if (dishesPrice == 0)
                                {
                                    return;
                                }
                                break;
                            }
                            else
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                setPosition(70, y + 2 + line);
                                cout << RED << "Please Enter number only!!" << RESET << endl;
                                idInputLine = y + 2 + line;
                                line++;
                            }
                        }
                        cin.ignore();
                        found = true;
                        food.name = dishesName;
                        food.price = dishesPrice;
                        updated = true;
                        line++;
                        break;
                    }
                }
                if (!found)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "NO ID Found" << RESET << endl;
                    line++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, y + 2 + line);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line++;
            }
        }
    }
    setPosition(70, idInputLine + 4);
    cout << YELLOW << "PRESS 1 to Confirm Updating OR PRESS 0 to Cancel Updating: " << RESET;
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
            setPosition(70, idInputLine + 6);
            cout << GREEN << "Dish Updated Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, idInputLine + 8);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}

void UpdateInSignature()
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
    setPosition(67, 3);
    cout << YELLOW << "Type Number 0 to Exit the Program and Cancel this Menu" << RESET << endl;
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
        cout << ORANGE << fixed << setprecision(2) << setw(5) << price << " $" << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "----------------------------------------------------------" << RESET << endl;
    file.close();

    int dishesId;
    string dishesName;
    double dishesPrice;
    bool found = false;
    bool updated = false;
    int idInputLine = y + 2;
    while (!updated)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Enter a dishes ID: " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> dishesId)
            {
                if (dishesId == 0)
                {
                    return;
                }
                for (Food &food : dishes)
                {
                    if (food.id == dishesId)
                    {
                        setPosition(70, y + 2 + line);
                        cout << YELLOW << "Enter new Dish Name: " << RESET;
                        line++;
                        cin.ignore();
                        getline(cin, dishesName);
                        if (dishesName == "0")
                        {
                            return;
                        }
                        while (true)
                        {
                            setPosition(70, y + 2 + line);
                            cout << YELLOW << "Enter a Dish Price: " << RESET;
                            line++;
                            if (cin >> dishesPrice)
                            {
                                if (dishesPrice == 0)
                                {
                                    return;
                                }
                                break;
                            }
                            else
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                setPosition(70, y + 2 + line);
                                cout << RED << "Please Enter number only!!" << RESET << endl;
                                idInputLine = y + 2 + line;
                                line++;
                            }
                        }
                        cin.ignore();
                        found = true;
                        food.name = dishesName;
                        food.price = dishesPrice;
                        updated = true;
                        line++;
                        break;
                    }
                }
                if (!found)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "NO ID Found" << RESET << endl;
                    line++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, y + 2 + line);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line++;
            }
        }
    }
    setPosition(70, idInputLine + 4);
    cout << YELLOW << "PRESS 1 to Confirm Updating OR PRESS 0 to Cancel Updating: " << RESET;
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
            setPosition(70, idInputLine + 6);
            cout << GREEN << "Dish Updated Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, idInputLine + 8);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}

void UpdateInFried()
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
    string dishesName;
    double dishesPrice;
    bool found = false;
    bool updated = false;
    int idInputLine = y + 2;
    while (!updated)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Enter a dishes ID: " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> dishesId)
            {
                if (dishesId == 0)
                {
                    return;
                }
                for (Food &food : dishes)
                {
                    if (food.id == dishesId)
                    {
                        setPosition(70, y + 2 + line);
                        cout << YELLOW << "Enter new Dish Name: " << RESET;
                        line++;
                        cin.ignore();
                        getline(cin, dishesName);
                        if (dishesName == "0")
                        {
                            return;
                        }
                        while (true)
                        {
                            setPosition(70, y + 2 + line);
                            cout << YELLOW << "Enter a Dish Price: " << RESET;
                            line++;
                            if (cin >> dishesPrice)
                            {
                                if (dishesPrice == 0)
                                {
                                    return;
                                }
                                break;
                            }
                            else
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                setPosition(70, y + 2 + line);
                                cout << RED << "Please Enter number only!!" << RESET << endl;
                                idInputLine = y + 2 + line;
                                line++;
                            }
                        }
                        cin.ignore();
                        found = true;
                        food.name = dishesName;
                        food.price = dishesPrice;
                        updated = true;
                        line++;
                        break;
                    }
                }
                if (!found)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "NO ID Found" << RESET << endl;
                    line++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, y + 2 + line);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line++;
            }
        }
    }
    setPosition(70, idInputLine + 4);
    cout << YELLOW << "PRESS 1 to Confirm Updating OR PRESS 0 to Cancel Updating: " << RESET;
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
            setPosition(70, idInputLine + 6);
            cout << GREEN << "Dish Updated Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, idInputLine + 8);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}

void UpdateInAppetizer()
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
    setPosition(67, 3);
    cout << YELLOW << "Type Number 0 to Exit the Program and Cancel this Menu" << RESET << endl;
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
    string dishesName;
    double dishesPrice;
    bool found = false;
    bool updated = false;
    int idInputLine = y + 2;
    while (!updated)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Enter a dishes ID: " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> dishesId)
            {
                if (dishesId == 0)
                {
                    return;
                }
                for (Food &food : dishes)
                {
                    if (food.id == dishesId)
                    {
                        setPosition(70, y + 2 + line);
                        cout << YELLOW << "Enter new Dish Name: " << RESET;
                        line++;
                        cin.ignore();
                        getline(cin, dishesName);
                        if (dishesName == "0")
                        {
                            return;
                        }
                        while (true)
                        {
                            setPosition(70, y + 2 + line);
                            cout << YELLOW << "Enter a Dish Price: " << RESET;
                            line++;
                            if (cin >> dishesPrice)
                            {
                                if (dishesPrice == 0)
                                {
                                    return;
                                }
                                break;
                            }
                            else
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                setPosition(70, y + 2 + line);
                                cout << RED << "Please Enter number only!!" << RESET << endl;
                                idInputLine = y + 2 + line;
                                line++;
                            }
                        }
                        cin.ignore();
                        found = true;
                        food.name = dishesName;
                        food.price = dishesPrice;
                        updated = true;
                        line++;
                        break;
                    }
                }
                if (!found)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "NO ID Found" << RESET << endl;
                    line++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, y + 2 + line);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line++;
            }
        }
    }
    setPosition(70, idInputLine + 4);
    cout << YELLOW << "PRESS 1 to Confirm Updating OR PRESS 0 to Cancel Updating: " << RESET;
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
            setPosition(70, idInputLine + 6);
            cout << GREEN << "Dish Updated Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, idInputLine + 8);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}

void UpdateInExtraMeat()
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
    setPosition(67, 3);
    cout << YELLOW << "Type Number 0 to Exit the Program and Cancel this Menu" << RESET << endl;
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
    string dishesName;
    double dishesPrice;
    bool found = false;
    bool updated = false;
    int idInputLine = y + 2;
    while (!updated)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Enter a dishes ID: " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> dishesId)
            {
                if (dishesId == 0)
                {
                    return;
                }
                for (Food &food : dishes)
                {
                    if (food.id == dishesId)
                    {
                        setPosition(70, y + 2 + line);
                        cout << YELLOW << "Enter new Dish Name: " << RESET;
                        line++;
                        cin.ignore();
                        getline(cin, dishesName);
                        if (dishesName == "0")
                        {
                            return;
                        }
                        while (true)
                        {
                            setPosition(70, y + 2 + line);
                            cout << YELLOW << "Enter a Dish Price: " << RESET;
                            line++;
                            if (cin >> dishesPrice)
                            {
                                if (dishesPrice == 0)
                                {
                                    return;
                                }
                                break;
                            }
                            else
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                setPosition(70, y + 2 + line);
                                cout << RED << "Please Enter number only!!" << RESET << endl;
                                idInputLine = y + 2 + line;
                                line++;
                            }
                        }
                        cin.ignore();
                        found = true;
                        food.name = dishesName;
                        food.price = dishesPrice;
                        updated = true;
                        line++;
                        break;
                    }
                }
                if (!found)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "NO ID Found" << RESET << endl;
                    line++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, y + 2 + line);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line++;
            }
        }
    }
    setPosition(70, idInputLine + 4);
    cout << YELLOW << "PRESS 1 to Confirm Updating OR PRESS 0 to Cancel Updating: " << RESET;
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
            setPosition(70, idInputLine + 6);
            cout << GREEN << "Dish Updated Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, idInputLine + 8);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}

void UpdateInComboSet()
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
    setPosition(67, 3);
    cout << YELLOW << "Type Number 0 to Exit the Program and Cancel this Menu" << RESET << endl;
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
    string dishesName;
    double dishesPrice;
    bool found = false;
    bool updated = false;
    int idInputLine = y + 2;
    while (!updated)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Enter a dishes ID: " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> dishesId)
            {
                if (dishesId == 0)
                {
                    return;
                }
                for (Food &food : dishes)
                {
                    if (food.id == dishesId)
                    {
                        setPosition(70, y + 2 + line);
                        cout << YELLOW << "Enter new Dish Name: " << RESET;
                        line++;
                        cin.ignore();
                        getline(cin, dishesName);
                        if (dishesName == "0")
                        {
                            return;
                        }
                        while (true)
                        {
                            setPosition(70, y + 2 + line);
                            cout << YELLOW << "Enter a Dish Price: " << RESET;
                            line++;
                            if (cin >> dishesPrice)
                            {
                                if (dishesPrice == 0)
                                {
                                    return;
                                }
                                break;
                            }
                            else
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                setPosition(70, y + 2 + line);
                                cout << RED << "Please Enter number only!!" << RESET << endl;
                                idInputLine = y + 2 + line;
                                line++;
                            }
                        }
                        cin.ignore();
                        found = true;
                        food.name = dishesName;
                        food.price = dishesPrice;
                        updated = true;
                        line++;
                        break;
                    }
                }
                if (!found)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "NO ID Found" << RESET << endl;
                    line++;
                }
                else
                {
                    break;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, y + 2 + line);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line++;
            }
        }
    }
    setPosition(70, idInputLine + 4);
    cout << YELLOW << "PRESS 1 to Confirm Updating OR PRESS 0 to Cancel Updating: " << RESET;
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
            setPosition(70, idInputLine + 6);
            cout << GREEN << "Dish Updated Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, idInputLine + 8);
    cin.ignore();
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.get();
    system("cls");
    return;
}

#endif