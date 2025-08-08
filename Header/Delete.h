#include <iostream>
#include <fstream>
#include <sstream>
#include "Design.h"

#ifndef DELETE_h
#define DELETE_h

// linked list for modify the data inside file io
struct Delete
{
    Food food;
    Delete *next;
};
struct DeleteList
{
    int n;
    Delete *head;
    Delete *tail;
};
DeleteList *createList()
{
    DeleteList *ls = new DeleteList;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}
void delete_first_id(DeleteList *ls)
{
    if (ls->n == 0)
    {
        return;
    }
    Delete *d = ls->head;
    ls->head = ls->head->next;
    delete d;
    if (ls->n == 1)
    {
        ls->tail = nullptr;
    }
    ls->n--;
}
void delete_last_id(DeleteList *ls)
{
    if (ls->n == 0)
    {
        return;
    }
    if (ls->n == 1)
    {
        delete ls->tail;
        ls->head = ls->tail = nullptr;
    }
    else
    {
        Delete *d = ls->head;
        while (d->next != ls->tail)
        {
            d = d->next;
        }
        d->next = nullptr;
        delete ls->tail;
        ls->tail = d;
    }
}

bool delete_on_Id(DeleteList *ls, int id)
{
    Delete *temp = ls->head;
    int count = 0;
    int pos = -1;
    while (temp != nullptr)
    {
        if (id == temp->food.id)
        {
            pos = count;
            break;
        }
        temp = temp->next;
        count++;
    }
    if (pos == -1)
    {
        return false;
    }
    if (pos == 0)
    {
        delete_first_id(ls);
        ls->n--;
    }
    else if (pos == ls->n - 1)
    {
        delete_last_id(ls);
        ls->n--;
    }
    else
    {
        Delete *current = ls->head;
        for (int i = 0; i < pos - 1; i++)
        {
            current = current->next;
        }
        Delete *deleteid = current->next;
        current->next = deleteid->next;
        delete deleteid;
        ls->n--;
    }
    return true;
}
void add_last_id(DeleteList *ls, Food food)
{
    Delete *d = new Delete();
    d->food.id = food.id;
    d->food.name = food.name;
    d->food.price = food.price;
    d->next = nullptr;
    if (ls->n == 0)
    {
        ls->head = d;
    }
    else
    {
        ls->tail->next = d;
    }
    ls->tail = d;
    ls->n++;
}
// Input all those data from file into delete linked list and then manipulate those data and store it back to file
void DeleteInSingleSet()
{
    ifstream inputfile;
    inputfile.open("Data/SingleSet.csv");
    if (!inputfile.is_open())
    {
        return;
    }

    DeleteList *dl = createList();
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
        Food food = {id, name, price};
        add_last_id(dl, food);
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
    int idInputLine = y + 2;
    bool deleted = false;
    bool found = false;
    while (!deleted)
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
                Delete *temp = dl->head;
                while (temp != nullptr)
                {
                    if (temp->food.id == dishesId)
                    {
                        found = delete_on_Id(dl, dishesId);
                        deleted = true;
                        break;
                    }
                    temp = temp->next;
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
    setPosition(70, idInputLine + 1);
    cout << YELLOW << "PRESS 1 to Confirm Deleting OR PRESS 0 to Cancel Deleting: " << RESET;
    int confirm;
    cin >> confirm;
    if (confirm == 1)
    {
        ofstream outputfile;
        outputfile.open("Data/SingleSet.csv", ios::trunc);
        if (!outputfile.is_open())
        {
            setPosition(70, idInputLine + 5);
            cout << RED << "File cannot be Opened" << RESET << endl;
        }
        else
        {
            outputfile << "ID,Name,Price\n";
            Delete *temp = dl->head;
            while (temp != nullptr)
            {
                outputfile << temp->food.id << ',' << temp->food.name << ',' << fixed << setprecision(2) << temp->food.price << endl;
                temp = temp->next;
            }
            outputfile.close();
            setPosition(70, idInputLine + 2);
            cout << GREEN << "Dish Deleted Successfully" << RESET << endl;
        }
    }
    else
    {
        return;
    }
    setPosition(70, idInputLine + 4);
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
    DeleteList *dl = createList();
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
        add_last_id(dl, food);
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
    int idInputLine = y + 2;
    bool deleted = false;
    bool found = false;
    while (!deleted)
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
                Delete *temp = dl->head;
                while (temp != nullptr)
                {
                    if (temp->food.id == dishesId)
                    {
                        found = delete_on_Id(dl, dishesId);
                        deleted = true;
                        break;
                    }
                    temp = temp->next;
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
            Delete *temp = dl->head;
            while (temp != nullptr)
            {
                outputfile << temp->food.id << ',' << temp->food.name << ',' << fixed << setprecision(2) << temp->food.price << endl;
                temp = temp->next;
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
    DeleteList *dl = createList();
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
        add_last_id(dl, food);
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
    int idInputLine = y + 2;
    bool deleted = false;
    bool found = false;
    while (!deleted)
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
                Delete *temp = dl->head;
                while (temp != nullptr)
                {
                    if (temp->food.id == dishesId)
                    {
                        found = delete_on_Id(dl, dishesId);
                        deleted = true;
                        break;
                    }
                    temp = temp->next;
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
            Delete *temp = dl->head;
            while (temp != nullptr)
            {
                outputfile << temp->food.id << ',' << temp->food.name << ',' << fixed << setprecision(2) << temp->food.price << endl;
                temp = temp->next;
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
    DeleteList *dl = createList();
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
        add_last_id(dl, food);
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
    int idInputLine = y + 2;
    bool deleted = false;
    bool found = false;
    while (!deleted)
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
                Delete *temp = dl->head;
                while (temp != nullptr)
                {
                    if (temp->food.id == dishesId)
                    {
                        found = delete_on_Id(dl, dishesId);
                        deleted = true;
                        break;
                    }
                    temp = temp->next;
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
            Delete *temp = dl->head;
            while (temp != nullptr)
            {
                outputfile << temp->food.id << ',' << temp->food.name << ',' << fixed << setprecision(2) << temp->food.price << endl;
                temp = temp->next;
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
    DeleteList *dl = createList();
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
        add_last_id(dl, food);
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
    int idInputLine = y + 2;
    bool deleted = false;
    bool found = false;
    while (!deleted)
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
                Delete *temp = dl->head;
                while (temp != nullptr)
                {
                    if (temp->food.id == dishesId)
                    {
                        found = delete_on_Id(dl, dishesId);
                        deleted = true;
                        break;
                    }
                    temp = temp->next;
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
            Delete *temp = dl->head;
            while (temp != nullptr)
            {
                outputfile << temp->food.id << ',' << temp->food.name << ',' << fixed << setprecision(2) << temp->food.price << endl;
                temp = temp->next;
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
    DeleteList *dl = createList();
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
        add_last_id(dl, food);
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
    int idInputLine = y + 2;
    bool deleted = false;
    bool found = false;
    while (!deleted)
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
                Delete *temp = dl->head;
                while (temp != nullptr)
                {
                    if (temp->food.id == dishesId)
                    {
                        found = delete_on_Id(dl, dishesId);
                        deleted = true;
                        break;
                    }
                    temp = temp->next;
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
            Delete *temp = dl->head;
            while (temp != nullptr)
            {
                outputfile << temp->food.id << ',' << temp->food.name << ',' << fixed << setprecision(2) << temp->food.price << endl;
                temp = temp->next;
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