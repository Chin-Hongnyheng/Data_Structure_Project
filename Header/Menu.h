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

    Queue *queue = EmptyQueue();
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
        // add to queue for customer to order
        Food food = {id, name, price};
        enqueue(queue, food);
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
    int order;
    double mealPrice = 0;
    int idInputLine = y + 2;
    int id;
    bool ordered = false;
    while (!ordered)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Choose your order (ID): " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> order)
            {
                if (order == 0)
                {
                    return;
                }
                bool found = false;

                Menu *current = queue->front;
                while (current != nullptr)
                {
                    if (order == current->food.id)
                    {
                        id = current->food.id;
                        meal = current->food.name;
                        mealPrice = current->food.price;
                        y = y + 2;
                        found = true;
                        ordered = true;
                        break;
                    }
                    current = current->next;
                }
                if (!found)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "This ID does not EXIST" << RESET << endl;
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
    int quantity;
    int line1 = 0;
    while (true)
    {
        setPosition(70, idInputLine + 1 + line1);
        cout << YELLOW << "Enter Quantity: " << RESET;
        line1++;
        if (cin >> quantity)
        {
            if (quantity == 0)
            {
                return;
            }
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            setPosition(70, idInputLine + 1 + line1);
            cout << RED << "Please Enter number only!!" << RESET << endl;
            line1++;
        }
    }

    setPosition(70, idInputLine + 4);
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
        int num;
        int line2 = 0;
        while (true)
        {
            setPosition(70, 5 + line2);
            cout << GREEN << "PRESS 1 To Make Another Order OR PRESS Any Number to Finish Your Order: " << RESET;
            line2++;
            if (cin >> num)
            {
                if (num == 1)
                {
                    return;
                }
                else
                {
                    system("cls");
                    printing();
                    system("cls");
                    Display(list);
                    SaveHistory(list);
                    break;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, 5 + line2);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line2++;
            }
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
    Queue *queue = EmptyQueue();
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
        Food food = {id, name, price};
        enqueue(queue, food);
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
    int order;
    double mealPrice = 0;
    int idInputLine = y + 2;
    int id;
    bool ordered = false;
    while (!ordered)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Choose your order (ID): " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> order)
            {
                if (order == 0)
                {
                    return;
                }
                bool found = false;

                Menu *current = queue->front;
                while (current != nullptr)
                {
                    if (order == current->food.id)
                    {
                        id = current->food.id;
                        meal = current->food.name;
                        mealPrice = current->food.price;
                        y = y + 2;
                        found = true;
                        ordered = true;
                        break;
                    }
                    current = current->next;
                }
                if (!found)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "This ID does not EXIST" << RESET << endl;
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
    int quantity;
    int line1 = 0;
    while (true)
    {
        setPosition(70, idInputLine + 1 + line1);
        cout << YELLOW << "Enter Quantity: " << RESET;
        line1++;
        if (cin >> quantity)
        {
            if (quantity == 0)
            {
                return;
            }
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            setPosition(70, idInputLine + 1 + line1);
            cout << RED << "Please Enter number only!!" << RESET << endl;
            line1++;
        }
    }

    setPosition(70, idInputLine + 4);
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
        int num;
        int line2 = 0;
        while (true)
        {
            setPosition(70, 5 + line2);
            cout << GREEN << "PRESS 1 To Make Another Order OR PRESS Any Number to Finish Your Order: " << RESET;
            line2++;
            if (cin >> num)
            {
                if (num == 1)
                {
                    return;
                }
                else
                {
                    system("cls");
                    printing();
                    system("cls");
                    Display(list);
                    SaveHistory(list);
                    break;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, 5 + line2);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line2++;
            }
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
    Queue *queue = EmptyQueue();
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
        // add to queue for customer to order
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

    string meal;
    int order;
    double mealPrice = 0;
    int idInputLine = y + 2;
    int id;
    bool ordered = false;
    while (!ordered)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Choose your order (ID): " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> order)
            {
                if (order == 0)
                {
                    return;
                }
                bool found = false;

                Menu *current = queue->front;
                while (current != nullptr)
                {
                    if (order == current->food.id)
                    {
                        id = current->food.id;
                        meal = current->food.name;
                        mealPrice = current->food.price;
                        y = y + 2;
                        found = true;
                        ordered = true;
                        break;
                    }
                    current = current->next;
                }
                if (!found)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "This ID does not EXIST" << RESET << endl;
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
    int quantity;
    int line1 = 0;
    while (true)
    {
        setPosition(70, idInputLine + 1 + line1);
        cout << YELLOW << "Enter Quantity: " << RESET;
        line1++;
        if (cin >> quantity)
        {
            if (quantity == 0)
            {
                return;
            }
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            setPosition(70, idInputLine + 1 + line1);
            cout << RED << "Please Enter number only!!" << RESET << endl;
            line1++;
        }
    }

    setPosition(70, idInputLine + 4);
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
        int num;
        int line2 = 0;
        while (true)
        {
            setPosition(70, 5 + line2);
            cout << GREEN << "PRESS 1 To Make Another Order OR PRESS Any Number to Finish Your Order: " << RESET;
            line2++;
            if (cin >> num)
            {
                if (num == 1)
                {
                    return;
                }
                else
                {
                    system("cls");
                    printing();
                    system("cls");
                    Display(list);
                    SaveHistory(list);
                    break;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, 5 + line2);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line2++;
            }
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
    Queue *queue = EmptyQueue();
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
        // add to queue for customer to order
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

    string meal;
    int order;
    double mealPrice = 0;
    int idInputLine = y + 2;
    int id;
    bool ordered = false;
    while (!ordered)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Choose your order (ID): " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> order)
            {
                if (order == 0)
                {
                    return;
                }
                bool found = false;

                Menu *current = queue->front;
                while (current != nullptr)
                {
                    if (order == current->food.id)
                    {
                        id = current->food.id;
                        meal = current->food.name;
                        mealPrice = current->food.price;
                        y = y + 2;
                        found = true;
                        ordered = true;
                        break;
                    }
                    current = current->next;
                }
                if (!found)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "This ID does not EXIST" << RESET << endl;
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
    int quantity;
    int line1 = 0;
    while (true)
    {
        setPosition(70, idInputLine + 1 + line1);
        cout << YELLOW << "Enter Quantity: " << RESET;
        line1++;
        if (cin >> quantity)
        {
            if (quantity == 0)
            {
                return;
            }
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            setPosition(70, idInputLine + 1 + line1);
            cout << RED << "Please Enter number only!!" << RESET << endl;
            line1++;
        }
    }

    setPosition(70, idInputLine + 4);
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
        int num;
        int line2 = 0;
        while (true)
        {
            setPosition(70, 5 + line2);
            cout << GREEN << "PRESS 1 To Make Another Order OR PRESS Any Number to Finish Your Order: " << RESET;
            line2++;
            if (cin >> num)
            {
                if (num == 1)
                {
                    return;
                }
                else
                {
                    system("cls");
                    printing();
                    system("cls");
                    Display(list);
                    SaveHistory(list);
                    break;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, 5 + line2);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line2++;
            }
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
        Queue *queue = EmptyQueue();
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
            // add to queue for customer to order
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

        string meal;
        int order;
        double mealPrice = 0;
        int idInputLine = y + 2;
        int id;
        bool ordered = false;
        while (!ordered)
        {
            int line = 0;
            while (true)
            {
                setPosition(70, y + 2 + line);
                cout << YELLOW << "Choose your order (ID): " << RESET;
                idInputLine = y + 2 + line;
                line++;
                if (cin >> order)
                {
                    if (order == 0)
                    {
                        return;
                    }
                    bool found = false;

                    Menu *current = queue->front;
                    while (current != nullptr)
                    {
                        if (order == current->food.id)
                        {
                            id = current->food.id;
                            meal = current->food.name;
                            mealPrice = current->food.price;
                            y = y + 2;
                            found = true;
                            ordered = true;
                            break;
                        }
                        current = current->next;
                    }
                    if (!found)
                    {
                        setPosition(70, y + 2 + line);
                        cout << RED << "This ID does not EXIST" << RESET << endl;
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
        int quantity;
        int line1 = 0;
        while (true)
        {
            setPosition(70, idInputLine + 1 + line1);
            cout << YELLOW << "Enter Quantity: " << RESET;
            line1++;
            if (cin >> quantity)
            {
                if (quantity == 0)
                {
                    return;
                }
                break;
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, idInputLine + 1 + line1);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line1++;
            }
        }

        setPosition(70, idInputLine + 4);
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
            int num;
            int line2 = 0;
            while (true)
            {
                setPosition(70, 5 + line2);
                cout << GREEN << "PRESS 1 To Make Another Order OR PRESS Any Number to Finish Your Order: " << RESET;
                line2++;
                if (cin >> num)
                {
                    if (num == 1)
                    {
                        return;
                    }
                    else
                    {
                        system("cls");
                        printing();
                        system("cls");
                        Display(list);
                        SaveHistory(list);
                        break;
                    }
                }
                else
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    setPosition(70, 5 + line2);
                    cout << RED << "Please Enter number only!!" << RESET << endl;
                    line2++;
                }
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
}

void ComboSet()
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
        // add to queue for customer to order
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

    string meal;
    int order;
    double mealPrice = 0;
    int idInputLine = y + 2;
    int id;
    bool ordered = false;
    while (!ordered)
    {
        int line = 0;
        while (true)
        {
            setPosition(70, y + 2 + line);
            cout << YELLOW << "Choose your order (ID): " << RESET;
            idInputLine = y + 2 + line;
            line++;
            if (cin >> order)
            {
                if (order == 0)
                {
                    return;
                }
                bool found = false;

                Menu *current = queue->front;
                while (current != nullptr)
                {
                    if (order == current->food.id)
                    {
                        id = current->food.id;
                        meal = current->food.name;
                        mealPrice = current->food.price;
                        y = y + 2;
                        found = true;
                        ordered = true;
                        break;
                    }
                    current = current->next;
                }
                if (!found)
                {
                    setPosition(70, y + 2 + line);
                    cout << RED << "This ID does not EXIST" << RESET << endl;
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
    int quantity;
    int line1 = 0;
    while (true)
    {
        setPosition(70, idInputLine + 1 + line1);
        cout << YELLOW << "Enter Quantity: " << RESET;
        line1++;
        if (cin >> quantity)
        {
            if (quantity == 0)
            {
                return;
            }
            break;
        }
        else
        {
            cin.clear();
            cin.ignore(1000, '\n');
            setPosition(70, idInputLine + 1 + line1);
            cout << RED << "Please Enter number only!!" << RESET << endl;
            line1++;
        }
    }
    setPosition(70, idInputLine + 4);
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
        int num;
        int line2 = 0;
        while (true)
        {
            setPosition(70, 5 + line2);
            cout << GREEN << "PRESS 1 To Make Another Order OR PRESS Any Number to Finish Your Order: " << RESET;
            line2++;
            if (cin >> num)
            {
                if (num == 1)
                {
                    return;
                }
                else
                {
                    system("cls");
                    printing();
                    system("cls");
                    Display(list);
                    SaveHistory(list);
                    break;
                }
            }
            else
            {
                cin.clear();
                cin.ignore(1000, '\n');
                setPosition(70, 5 + line2);
                cout << RED << "Please Enter number only!!" << RESET << endl;
                line2++;
            }
        }
    }

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
