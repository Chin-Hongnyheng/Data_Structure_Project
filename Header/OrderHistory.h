#include <iostream>
#include "Design.h"
// getting the receipt Paper to display
#include "Receipt.h"
using namespace std;
#ifndef Order_h
#define Order_h

void Order(List *ls)
{

    if (ls->n > 0)
    {
        printed = false;
    }
    if (!printed)
    {
        system("cls");
        int y = ReceiptPaper(ls);
        setPosition(70, y + 1);
        cout << YELLOW << "PRESS 1 to Add More Order" << RESET << endl;
        setPosition(70, y + 2);
        cout << YELLOW << "PRESS 2 To Delete An Existing Order" << RESET << endl;
        setPosition(70, y + 3);
        cout << YELLOW << "PRESS 3 To Modify Your Order" << RESET << endl;
        setPosition(70, y + 4);
        cout << YELLOW << "PRESS 4 To Confirm Your Order OR PRESS Any Number To Cancel Your Whole Order" << RESET << endl;
        setPosition(70, y + 5);
        cout << YELLOW << "Enter an option: " << RESET;
        int opt;
        cin >> opt;
        if (opt == 1)
        {
            system("cls");
            printed = false;
            return;
        }
        else if (opt == 2)
        {
            int attempt = 0;
            while (true)
            {
                setPosition(70, y + 7);
                cout << YELLOW << "Enter an ID: " << RESET;
                int id;
                cin >> id;
                bool found = delete_id(ls, id);
                if (!found)
                {
                    setPosition(70, y + 8);
                    cout << RED << "ID NOT FOUND" << RESET << endl;
                    y += 2;
                }
                else
                {
                    setPosition(70, y + 9);
                    cout << GREEN << "ID: " << id << " DELETED SUCCESSFULLY" << RESET << endl;
                    attempt += 2;
                    break;
                }
            }
            setPosition(70, y + 10 + attempt);
            cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
            cin.ignore();
            cin.get();
            system("cls");
            return;
        }
        else if (opt == 3)
        {
            int attempt = 0;
            while (true)
            {
                setPosition(70, y + 7);
                cout << YELLOW << "Enter an ID: " << RESET;
                int id;
                cin >> id;
                bool found = search_id(ls, id);
                if (!found)
                {
                    setPosition(70, y + 8);
                    cout << RED << "ID NOT FOUND" << RESET << endl;
                    y += 2;
                }
                else
                {
                    setPosition(70, y + 8);
                    cout << YELLOW << "Enter a new Quantity: " << RESET;
                    int quantity;
                    cin >> quantity;
                    bool success = modify_quantity(ls, id, quantity);
                    if (success)
                    {
                        setPosition(70, y + 10);
                        cout << GREEN << "Modify Successfully" << RESET << endl;
                        attempt += 2;
                    }
                    else
                    {
                        setPosition(70, y + 10);
                        cout << RED << "Modify Fail!!" << RESET << RESET << endl;
                        attempt += 2;
                    }
                    break;
                }
            }
            setPosition(70, y + 10 + attempt);
            cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
            cin.ignore();
            cin.get();
            system("cls");
            return;
        }
        else if (opt == 4)
        {
            system("cls");
            printing();
            system("cls");
            Display(list);
            SaveHistory(list);
            printed = true;
            setPosition(70, y + 5);
            cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
            cin.ignore();
            cin.get();
            system("cls");
            return;
        }

        else
        {
            delete_all(ls);
            printed = true;
            return;
        }
    }
    else
    {
        system("cls");
        setPosition(70, 5);
        cout << RED << "No Order List" << RESET << endl;
        setPosition(70, 6);
        cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
        cin.ignore();
        cin.get();
        system("cls");
    }
}
#endif