#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Design.h"
#include "Receipt.h"
#include <vector>
using namespace std;
#ifndef MENU_H
#define MENU_H

// Create a List to store Ordered Food
List *list = EmptyList();

void SingleSet()
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

    string meal;
    double mealPrice = 0;
    int id;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Choose your order (ID): " << RESET;
        int order;
        cin >> order;
        bool found = false;
        for (Food food : dishes)
        {
            if (order == food.id)
            {
                id = food.id;
                meal = food.name;
                mealPrice = food.price;
                y = y + 2;
                found = true;
                break;
            }
        }
        if (!found)
        {
            setPosition(70, y + 3);
            cout << RED << "This ID does not EXIST" << RESET << endl;
            y = y + 2;
            continue;
        }
        else
        {
            break;
        }
    }
    setPosition(70, y + 1);
    cout << YELLOW << "Enter Quantity: " << RESET;
    int quantity;
    cin >> quantity;
    setPosition(70, y + 2);
    cout << YELLOW << "PRESS 1 to Confirm your Order OR PRESS 0 to Cancel your Order: ";
    int verify;
    cin >> verify;

    if (verify == 1)
    {
        setPosition(70, y + 4);
        cout << GREEN << "Order Complete" << RESET << endl;
        Receipt receipt = {id, meal, mealPrice, quantity};
        // pass into receipt header
        add_last(list, receipt);
        system("cls");
        setPosition(70, 5);
        cout << GREEN << "PRESS 1 To Make Another Order OR PRESS Any Number to Finish Your Order: " << RESET;
        int num;
        cin >> num;
        if (num == 1)
        {
            printed = false;
            return;
        }
        else
        {
            system("cls");
            Display(list);
            SaveHistory(list);
        }
    }
    else if (verify == 0)
    {
        return;
    }
    setPosition(70, y + 1);
    cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
    return;
}

void SignatureFood()
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

    string meal;
    double mealPrice = 0;
    int id;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Choose your order (ID): " << RESET;
        int order;
        cin >> order;
        bool found = false;
        for (Food food : dishes)
        {
            if (order == food.id)
            {
                id = food.id;
                meal = food.name;
                mealPrice = food.price;
                y = y + 2;
                found = true;
                break;
            }
        }
        if (!found)
        {
            setPosition(70, y + 3);
            cout << RED << "This ID does not EXIST" << RESET << endl;
            y = y + 2;
            continue;
        }
        else
        {
            break;
        }
    }

    setPosition(70, y + 1);
    cout << YELLOW << "Enter Quantity: " << RESET;
    int quantity;
    cin >> quantity;
    setPosition(70, y + 2);
    cout << YELLOW << "PRESS 1 to Confirm your Order OR PRESS 0 to Cancel your Order: ";
    int verify;
    cin >> verify;

    if (verify == 1)
    {
        setPosition(70, y + 4);
        cout << GREEN << "Order Complete" << RESET << endl;
        Receipt receipt = {id, meal, mealPrice, quantity};
        add_last(list, receipt);
        system("cls");
        setPosition(70, 5);
        cout << GREEN << "PRESS 1 To Make Another Order OR PRESS Any Number to Finish Your Order: " << RESET;
        int num;
        cin >> num;
        if (num == 1)
        {
            return;
        }
        else
        {
            system("cls");
            Display(list);
            SaveHistory(list);
        }
    }
    else if (verify == 0)
    {
        return;
    }
    setPosition(70, y + 1);
    cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
    return;
}

void Fried()
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

    string meal;
    double mealPrice = 0;
    int id;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Choose your order (ID): " << RESET;
        int order;
        cin >> order;
        bool found = false;
        for (Food food : dishes)
        {
            if (order == food.id)
            {
                id = food.id;
                meal = food.name;
                mealPrice = food.price;
                y = y + 2;
                found = true;
                break;
            }
        }
        if (!found)
        {
            setPosition(70, y + 3);
            cout << RED << "This ID does not EXIST" << RESET << endl;
            y = y + 2;
            continue;
        }
        else
        {
            break;
        }
    }

    setPosition(70, y + 1);
    cout << YELLOW << "Enter Quantity: " << RESET;
    int quantity;
    cin >> quantity;
    setPosition(70, y + 2);
    cout << YELLOW << "PRESS 1 to Confirm your Order OR PRESS 0 to Cancel your Order: ";
    int verify;
    cin >> verify;

    if (verify == 1)
    {
        setPosition(70, y + 4);
        cout << GREEN << "Order Complete" << RESET << endl;
        Receipt receipt = {id, meal, mealPrice, quantity};
        add_last(list, receipt);
        system("cls");
        setPosition(70, 5);
        cout << GREEN << "PRESS 1 To Make Another Order OR PRESS Any Number to Finish Your Order: " << RESET;
        int num;
        cin >> num;
        if (num == 1)
        {
            return;
        }
        else
        {
            system("cls");
            Display(list);
            SaveHistory(list);
        }
    }
    else if (verify == 0)
    {
        return;
    }
    setPosition(70, y + 1);
    cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
    return;
}

void Appetizer()
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

    string meal;
    double mealPrice = 0;
    int id;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Choose your order (ID): " << RESET;
        int order;
        cin >> order;
        bool found = false;
        for (Food food : dishes)
        {
            if (order == food.id)
            {
                id = food.id;
                meal = food.name;
                mealPrice = food.price;
                y = y + 2;
                found = true;
                break;
            }
        }
        if (!found)
        {
            setPosition(70, y + 3);
            cout << RED << "This ID does not EXIST" << RESET << endl;
            y = y + 2;
            continue;
        }
        else
        {
            break;
        }
    }
    setPosition(70, y + 1);
    cout << YELLOW << "Enter Quantity: " << RESET;
    int quantity;
    cin >> quantity;
    setPosition(70, y + 2);
    cout << YELLOW << "PRESS 1 to Confirm your Order OR PRESS 0 to Cancel your Order: ";
    int verify;
    cin >> verify;

    if (verify == 1)
    {
        setPosition(70, y + 4);
        cout << GREEN << "Order Complete" << RESET << endl;
        Receipt receipt = {id, meal, mealPrice, quantity};
        add_last(list, receipt);
        system("cls");
        setPosition(70, 5);
        cout << GREEN << "PRESS 1 To Make Another Order OR PRESS Any Number to Finish Your Order: " << RESET;
        int num;
        cin >> num;
        if (num == 1)
        {
            return;
        }
        else
        {
            system("cls");
            Display(list);
            SaveHistory(list);
        }
    }
    else if (verify == 0)
    {
        return;
    }
    setPosition(70, y + 1);
    cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
    return;
}

void ExtraMeat()
{
    while (true)
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

        string meal;
        double mealPrice = 0;
        int id;
        while (true)
        {
            setPosition(70, y + 2);
            cout << YELLOW << "Choose your order (ID): " << RESET;
            int order;
            cin >> order;
            bool found = false;
            for (Food food : dishes)
            {
                if (order == food.id)
                {
                    id = food.id;
                    meal = food.name;
                    mealPrice = food.price;
                    y = y + 2;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                setPosition(70, y + 3);
                cout << RED << "This ID does not EXIST" << RESET << endl;
                y = y + 2;
                continue;
            }
            else
            {
                break;
            }
        }
        setPosition(70, y + 1);
        cout << YELLOW << "Enter Quantity: " << RESET;
        int quantity;
        cin >> quantity;
        setPosition(70, y + 2);
        cout << YELLOW << "PRESS 1 to Confirm your Order OR PRESS 0 to Cancel your Order: ";
        int verify;
        cin >> verify;

        if (verify == 1)
        {
            setPosition(70, y + 4);
            cout << GREEN << "Order Complete" << RESET << endl;
            Receipt receipt = {id, meal, mealPrice, quantity};
            add_last(list, receipt);
            system("cls");
            setPosition(70, 5);
            cout << GREEN << "PRESS 1 To Make Another Order OR PRESS Any Number to Finish Your Order: " << RESET;
            int num;
            cin >> num;
            if (num == 1)
            {
                system("cls");
                continue;
            }
            else
            {
                system("cls");
                Display(list);
                SaveHistory(list);
                break;
            }
        }
        else if (verify == 0)
        {
            return;
        }
    }
}

void ComboSet()
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

    string meal;
    double mealPrice = 0;
    int id;
    while (true)
    {
        setPosition(70, y + 2);
        cout << YELLOW << "Choose your order (ID): " << RESET;
        int order;
        cin >> order;
        bool found = false;
        for (Food food : dishes)
        {
            if (order == food.id)
            {
                id = food.id;
                meal = food.name;
                mealPrice = food.price;
                y = y + 2;
                found = true;
                break;
            }
        }
        if (!found)
        {
            setPosition(70, y + 3);
            cout << RED << "This ID does not EXIST" << RESET << endl;
            y = y + 2;
            continue;
        }
        else
        {
            break;
        }
    }
    setPosition(70, y + 1);
    cout << YELLOW << "Enter Quantity: " << RESET;
    int quantity;
    cin >> quantity;
    setPosition(70, y + 2);
    cout << YELLOW << "PRESS 1 to Confirm your Order OR PRESS 0 to Cancel your Order: ";
    int verify;
    cin >> verify;

    if (verify == 1)
    {
        Receipt receipt = {id, meal, mealPrice, quantity};
        add_last(list, receipt);
        system("cls");
        setPosition(70, 5);
        char c;
        cout << YELLOW << "Would you like to add more Meat?(Y/N): " << RESET;
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            system("cls");
            ExtraMeat();
        }
    }
    else if (verify == 0)
    {
        return;
    }
    setPosition(70, y + 1);
    cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
    return;
}
#endif
