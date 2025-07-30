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

    Queue *queue = EmptyQueue();
    string line;
    getline(file, line);
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
    while (getline(file, line))
    {
        stringstream ss(line);
        string name, idstr, priceStr;

        getline(ss, idstr, ',');
        getline(ss, name, ',');
        getline(ss, priceStr, ',');
        int id = stoi(idstr);
        double price = stod(priceStr);
        Food food = {id, name, price};
        enqueue(queue, food);
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

    int newId;
    int idInputLine = y + 2;
    while (true)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Add your new Dish (ID): " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> newId)
            {
                if (newId == 0)
                {
                    return;
                }
                bool exist = false;
                Menu *m = queue->front;
                while (m != nullptr)
                {
                    if (newId == m->food.id)
                    {
                        exist = true;
                        break;
                    }
                    m = m->next;
                }
                if (exist)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "This ID already exists! Try again!!." << RESET << endl;
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
        cin.ignore();
        setPosition(70, idInputLine + 1);
        cout << YELLOW << "Enter a new Dish name: " << RESET;
        string dishName;
        getline(cin, dishName);
        if (dishName == "0")
        {
            return;
        }
        double dishPrice;
        int line1 = 0;
        while (true)
        {
            setPosition(70, idInputLine + 2 + line1);
            cout << YELLOW << "Enter a Dish Price: " << RESET;
            line1++;
            if (cin >> dishPrice)
            {
                if (dishPrice == 0)
                {
                    return;
                }
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, idInputLine + 2 + line1);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line1++;
            }
        }
        setPosition(70, idInputLine + 3);
        cout << YELLOW << "PRESS 1 to Confirm your ADDING OR PRESS 0 to Cancel your ADDING: ";
        int verify;
        cin >> verify;

        if (verify == 1)
        {
            setPosition(70, idInputLine + 4);
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
        setPosition(70, idInputLine + 6);
        cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
}
void AddInSignature()
{
    ifstream file;
    file.open("Data/SignatureFood.csv");
    if (!file.is_open())
    {
        return;
    }
    Queue *queue = EmptyQueue();
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
        Food food = {id, name, price};
        enqueue(queue, food);
        setPosition(70, y);
        cout << YELLOW << "| " << RESET << ORANGE << id << RESET;
        setPosition(80, y);
        cout << ORANGE << name << RESET;
        setPosition(118, y);
        cout << ORANGE << fixed << setprecision(2) << setw(5) << price << " $" << RESET << YELLOW << " |" << RESET << endl;
        y++;
    }
    setPosition(70, y);
    cout << YELLOW << "----------------------------------------------------------" << RESET << endl;

    int newId;
    int idInputLine = y + 2;
    while (true)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Add your new Dish (ID): " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> newId)
            {
                if (newId == 0)
                {
                    return;
                }
                bool exist = false;
                Menu *m = queue->front;
                while (m != nullptr)
                {
                    if (newId == m->food.id)
                    {
                        exist = true;
                        break;
                    }
                    m = m->next;
                }
                if (exist)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "This ID already exists! Try again!!." << RESET << endl;
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
        cin.ignore();
        setPosition(70, idInputLine + 1);
        cout << YELLOW << "Enter a new Dish name: " << RESET;
        string dishName;
        getline(cin, dishName);
        if (dishName == "0")
        {
            return;
        }
        double dishPrice;
        int line1 = 0;
        while (true)
        {
            setPosition(70, idInputLine + 2 + line1);
            cout << YELLOW << "Enter a Dish Price: " << RESET;
            line1++;
            if (cin >> dishPrice)
            {
                if (dishPrice == 0)
                {
                    return;
                }
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, idInputLine + 2 + line1);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line1++;
            }
        }
        setPosition(70, idInputLine + 3);
        cout << YELLOW << "PRESS 1 to Confirm your ADDING OR PRESS 0 to Cancel your ADDING: ";
        int verify;
        cin >> verify;

        if (verify == 1)
        {
            setPosition(70, idInputLine + 4);
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
        setPosition(70, idInputLine + 6);
        cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
}

void AddInFried()
{
    ifstream file;
    file.open("Data/Fried.csv");
    if (!file.is_open())
    {
        return;
    }
    Queue *queue = EmptyQueue();
    string line;
    getline(file, line);
    setPosition(67, 3);
    cout << YELLOW << "Type Number 0 to Exit the Program and Cancel this Menu" << RESET << endl;
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
        Food food = {id, name, price};
        enqueue(queue, food);
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
    int idInputLine = y + 2;
    while (true)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Add your new Dish (ID): " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> newId)
            {
                if (newId == 0)
                {
                    return;
                }
                bool exist = false;
                Menu *m = queue->front;
                while (m != nullptr)
                {
                    if (newId == m->food.id)
                    {
                        exist = true;
                        break;
                    }
                    m = m->next;
                }
                if (exist)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "This ID already exists! Try again!!." << RESET << endl;
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
        cin.ignore();
        setPosition(70, idInputLine + 1);
        cout << YELLOW << "Enter a new Dish name: " << RESET;
        string dishName;
        getline(cin, dishName);
        if (dishName == "0")
        {
            return;
        }
        double dishPrice;
        int line1 = 0;
        while (true)
        {
            setPosition(70, idInputLine + 2 + line1);
            cout << YELLOW << "Enter a Dish Price: " << RESET;
            line1++;
            if (cin >> dishPrice)
            {
                if (dishPrice == 0)
                {
                    return;
                }
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, idInputLine + 2 + line1);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line1++;
            }
        }
        setPosition(70, idInputLine + 3);
        cout << YELLOW << "PRESS 1 to Confirm your ADDING OR PRESS 0 to Cancel your ADDING: ";
        int verify;
        cin >> verify;

        if (verify == 1)
        {
            setPosition(70, idInputLine + 4);
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
        setPosition(70, idInputLine + 6);
        cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
}

void AddInAppetizer()
{
    ifstream file;
    file.open("Data/Appetizer.csv");
    if (!file.is_open())
    {
        return;
    }
    Queue *queue = EmptyQueue();
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
        Food food = {id, name, price};
        enqueue(queue, food);
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
    int idInputLine = y + 2;
    while (true)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Add your new Dish (ID): " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> newId)
            {
                if (newId == 0)
                {
                    return;
                }
                bool exist = false;
                Menu *m = queue->front;
                while (m != nullptr)
                {
                    if (newId == m->food.id)
                    {
                        exist = true;
                        break;
                    }
                    m = m->next;
                }
                if (exist)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "This ID already exists! Try again!!." << RESET << endl;
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
        cin.ignore();
        setPosition(70, idInputLine + 1);
        cout << YELLOW << "Enter a new Dish name: " << RESET;
        string dishName;
        getline(cin, dishName);
        if (dishName == "0")
        {
            return;
        }
        double dishPrice;
        int line1 = 0;
        while (true)
        {
            setPosition(70, idInputLine + 2 + line1);
            cout << YELLOW << "Enter a Dish Price: " << RESET;
            line1++;
            if (cin >> dishPrice)
            {
                if (dishPrice == 0)
                {
                    return;
                }
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, idInputLine + 2 + line1);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line1++;
            }
        }
        setPosition(70, idInputLine + 3);
        cout << YELLOW << "PRESS 1 to Confirm your ADDING OR PRESS 0 to Cancel your ADDING: ";
        int verify;
        cin >> verify;

        if (verify == 1)
        {
            setPosition(70, idInputLine + 4);
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
        setPosition(70, idInputLine + 6);
        cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
}

void AddInCombo()
{
    ifstream file;
    file.open("Data/ComboSet.csv");
    if (!file.is_open())
    {
        return;
    }
    Queue *queue = EmptyQueue();
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
        Food food = {id, name, price};
        enqueue(queue, food);
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
    int idInputLine = y + 2;
    while (true)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Add your new Dish (ID): " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> newId)
            {
                if (newId == 0)
                {
                    return;
                }
                bool exist = false;
                Menu *m = queue->front;
                while (m != nullptr)
                {
                    if (newId == m->food.id)
                    {
                        exist = true;
                        break;
                    }
                    m = m->next;
                }
                if (exist)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "This ID already exists! Try again!!." << RESET << endl;
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
        cin.ignore();
        setPosition(70, idInputLine + 1);
        cout << YELLOW << "Enter a new Dish name: " << RESET;
        string dishName;
        getline(cin, dishName);
        if (dishName == "0")
        {
            return;
        }
        double dishPrice;
        int line1 = 0;
        while (true)
        {
            setPosition(70, idInputLine + 2 + line1);
            cout << YELLOW << "Enter a Dish Price: " << RESET;
            line1++;
            if (cin >> dishPrice)
            {
                if (dishPrice == 0)
                    ;
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, idInputLine + 2 + line1);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line1++;
            }
        }
        setPosition(70, idInputLine + 3);
        cout << YELLOW << "PRESS 1 to Confirm your ADDING OR PRESS 0 to Cancel your ADDING: ";
        int verify;
        cin >> verify;

        if (verify == 1)
        {
            setPosition(70, idInputLine + 4);
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
        setPosition(70, idInputLine + 6);
        cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
}

void AddInExtraMeat()
{
    ifstream file;
    file.open("Data/Extra.csv");
    if (!file.is_open())
    {
        return;
    }
    Queue *queue = EmptyQueue();
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
        Food food = {id, name, price};
        enqueue(queue, food);
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
    int idInputLine = y + 2;
    while (true)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Add your new Dish (ID): " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> newId)
            {
                if (newId == 0)
                {
                    return;
                }
                bool exist = false;
                Menu *m = queue->front;
                while (m != nullptr)
                {
                    if (newId == m->food.id)
                    {
                        exist = true;
                        break;
                    }
                    m = m->next;
                }
                if (exist)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "This ID already exists! Try again!!." << RESET << endl;
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
        cin.ignore();
        setPosition(70, idInputLine + 1);
        cout << YELLOW << "Enter a new Dish name: " << RESET;
        string dishName;
        getline(cin, dishName);
        if (dishName == "0")
        {
            return;
        }
        double dishPrice;
        int line1 = 0;
        while (true)
        {
            setPosition(70, idInputLine + 2 + line1);
            cout << YELLOW << "Enter a Dish Price: " << RESET;
            line1++;
            if (cin >> dishPrice)
            {
                if (dishPrice == 0)
                {
                    return;
                }
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, idInputLine + 2 + line1);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line1++;
            }
        }
        setPosition(70, idInputLine + 3);
        cout << YELLOW << "PRESS 1 to Confirm your ADDING OR PRESS 0 to Cancel your ADDING: ";
        int verify;
        cin >> verify;

        if (verify == 1)
        {
            setPosition(70, idInputLine + 4);
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
        setPosition(70, idInputLine + 6);
        cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
}
#endif