#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <fstream>
#include "Header/Design.h"
#include "Header/Login.h"
#include "Header/SignUp.h"
#include "Header/Menu.h"
#include "Header/DisplayDIshes.h"
#include "Header/Add.h"
#include "Header/Update.h"
#include "Header/Delete.h"
#include "Header/History.h"
#include "Header/Earning.h"
#include "Header/Registered.h"
#include "Header/OrderHistory.h"

using namespace std;

int main()
{
    // Title();
    while (true)
    {
        setPosition(80, 5);
        cout << GREEN << ":::: Welcome to BAYMAK ::::" << endl;
        setPosition(80, 7);
        cout << "1. Log In" << endl;
        setPosition(80, 8);
        cout << "2. Sign Up" << endl;
        setPosition(80, 9);
        cout << "3. About us" << endl;
        setPosition(80, 10);
        cout << "4. Description" << endl;
        setPosition(80, 11);
        cout << "5. Exit" << endl;
        setPosition(80, 13);
        cout << "Choose an option: " << RESET;
        int opt;
        cin >> opt;
        switch (opt)
        {
        case 1:
        {
            bool found = login();
            if (found)
            {
                bool Exitloop = true;
                while (Exitloop)
                {
                    setPosition(80, 5);
                    cout << GREEN << "===== BAYMAK ======" << RESET << endl;
                    setPosition(80, 7);
                    cout << GREEN << "1. Place an order" << RESET << endl;
                    setPosition(80, 8);
                    cout << GREEN << "2. Rating" << RESET << endl;
                    setPosition(80, 9);
                    cout << GREEN << "3. Feed Back" << RESET << endl;
                    setPosition(80, 10);
                    cout << GREEN << "4. Admin Panel" << RESET << endl;
                    setPosition(80, 11);
                    cout << GREEN << "5. Order History" << RESET << endl;
                    setPosition(80, 12);
                    cout << GREEN << "6. Log Out" << RESET << endl;
                    setPosition(80, 14);
                    cout << GREEN << "Choose an option: " << RESET;
                    int opt1;
                    cin >> opt1;
                    switch (opt1)
                    {
                    case 1:
                    {
                        bool loop = true;
                        while (loop)
                        {
                            system("cls");
                            setPosition(80, 5);
                            cout << GREEN << "==== MENU ====" << RESET << endl;
                            setPosition(80, 7);
                            cout << GREEN << "1. Single Set" << RESET << endl;
                            setPosition(80, 8);
                            cout << GREEN << "2. Signature Food" << RESET << endl;
                            setPosition(80, 9);
                            cout << GREEN << "3. Fried" << RESET << endl;
                            setPosition(80, 10);
                            cout << GREEN << "4. Appetizer" << RESET << endl;
                            setPosition(80, 11);
                            cout << GREEN << "5. Combo Set" << RESET << endl;
                            setPosition(80, 12);
                            cout << GREEN << "6. Back" << RESET << endl;
                            setPosition(80, 14);
                            cout << GREEN << "Choose an option: " << RESET;
                            int opt2;
                            cin >> opt2;
                            switch (opt2)
                            {
                            case 1:
                                system("cls");
                                SingleSet();
                                break;
                            case 2:
                                system("cls");
                                SignatureFood();
                                break;
                            case 3:
                                system("cls");
                                Fried();
                                break;
                            case 4:
                                system("cls");
                                Appetizer();
                                break;
                            case 5:
                                system("cls");
                                ComboSet();
                                break;
                            case 6:
                                loop = false;
                                system("cls");
                                break;
                            default:
                                break;
                            }
                        }
                        break;
                    }
                    case 2:

                        break;
                    case 3:

                        break;
                    case 4:
                    {
                        bool found = verifyAdmin();
                        if (found)
                        {
                            bool adminLoop = true;
                            while (adminLoop)
                            {
                                system("cls");
                                setPosition(80, 5);
                                cout << GREEN << "**** Admin Panel ****" << endl;
                                setPosition(80, 6);
                                cout << "1. Add a new Dishes" << endl;
                                setPosition(80, 7);
                                cout << "2. Display Dishes" << endl;
                                setPosition(80, 8);
                                cout << "3. Update Dishes" << endl;
                                setPosition(80, 9);
                                cout << "4. Total Earning" << endl;
                                setPosition(80, 10);
                                cout << "5. Registered User" << endl;
                                setPosition(80, 11);
                                cout << "6. Delete Dishes" << endl;
                                setPosition(80, 12);
                                cout << "7. View Sale History" << endl;
                                setPosition(80, 13);
                                cout << "8. Back" << endl;
                                setPosition(80, 15);
                                cout << "Choose an option: " << RESET;
                                int opt3;
                                cin >> opt3;
                                switch (opt3)
                                {
                                case 1:
                                {
                                    bool addLoop = true;
                                    while (addLoop)
                                    {
                                        displayMenu();
                                        setPosition(80, 15);
                                        cout << GREEN << "Choose an option: " << RESET;
                                        int opt5;
                                        cin >> opt5;
                                        switch (opt5)
                                        {
                                        case 1:
                                            system("cls");
                                            AddInSingleSet();
                                            break;
                                        case 2:
                                            system("cls");
                                            AddInSignature();
                                            break;
                                        case 3:
                                            system("cls");
                                            AddInFried();
                                            break;
                                        case 4:
                                            system("cls");
                                            AddInAppetizer();
                                            break;
                                        case 5:
                                            system("cls");
                                            AddInCombo();
                                            break;
                                        case 6:
                                            system("cls");
                                            AddInExtraMeat();
                                            break;
                                        case 7:
                                            system("cls");
                                            addLoop = false;
                                            system("cls");
                                            break;
                                        default:
                                            system("cls");
                                            cout << RED << "Incorrect Input" << RESET << endl;
                                            break;
                                        }
                                    }
                                }
                                break;
                                case 2:
                                {
                                    bool menuLoop = true;
                                    while (menuLoop)
                                    {
                                        displayMenu();
                                        setPosition(80, 15);
                                        cout << GREEN << "Choose an option: " << RESET;
                                        int opt4;
                                        cin >> opt4;
                                        switch (opt4)
                                        {
                                        case 1:
                                            system("cls");
                                            displaySingleSet();
                                            break;
                                        case 2:
                                            system("cls");
                                            displaySignature();
                                            break;
                                        case 3:
                                            system("cls");
                                            displayFried();
                                            break;
                                        case 4:
                                            system("cls");
                                            displayAppetizer();
                                            break;
                                        case 5:
                                            system("cls");
                                            displayComboSet();
                                            break;
                                        case 6:
                                            system("cls");
                                            displayExtraMeat();
                                            break;
                                        case 7:
                                            system("cls");
                                            menuLoop = false;
                                            system("cls");
                                            break;
                                        default:
                                            system("cls");
                                            cout << RED << "Incorrect Input" << RESET << endl;
                                            break;
                                        }
                                    }
                                }
                                break;
                                case 3:
                                {
                                    bool UpdateLoop = true;
                                    while (UpdateLoop)
                                    {
                                        displayMenu();
                                        setPosition(80, 15);
                                        cout << GREEN << "Choose an option: " << RESET;
                                        int opt5;
                                        cin >> opt5;
                                        switch (opt5)
                                        {
                                        case 1:
                                            system("cls");
                                            UpdateInSingleSet();
                                            break;
                                        case 2:
                                            system("cls");
                                            UpdateInSignature();
                                            break;
                                        case 3:
                                            system("cls");
                                            UpdateInFried();
                                            break;
                                        case 4:
                                            system("cls");
                                            UpdateInAppetizer();
                                            break;
                                        case 5:
                                            system("cls");
                                            UpdateInComboSet();
                                            break;
                                        case 6:
                                            system("cls");
                                            UpdateInExtraMeat();
                                            break;
                                        case 7:
                                            system("cls");
                                            UpdateLoop = false;
                                            system("cls");
                                            break;
                                        default:
                                            system("cls");
                                            cout << RED << "Incorrect Input" << RESET << endl;
                                            break;
                                        }
                                    }
                                }
                                break;
                                case 4:
                                    system("cls");
                                    Earning();
                                    break;
                                case 5:
                                    system("cls");
                                    displayRegistered();
                                    break;
                                case 6:
                                {
                                    bool deleteLoop = true;
                                    while (deleteLoop)
                                    {
                                        displayMenu();
                                        setPosition(80, 15);
                                        cout << GREEN << "Choose an option: " << RESET;
                                        int opt6;
                                        cin >> opt6;
                                        switch (opt6)
                                        {
                                        case 1:
                                            system("cls");
                                            DeleteInSingleSet();
                                            break;
                                        case 2:
                                            system("cls");
                                            DeleteInSignature();
                                            break;
                                        case 3:
                                            system("cls");
                                            DeleteInFried();
                                            break;
                                        case 4:
                                            system("cls");
                                            DeleteInAppetizer();
                                            break;
                                        case 5:
                                            system("cls");
                                            DeleteInCombo();
                                            break;
                                        case 6:
                                            system("cls");
                                            DeleteInExtraMeat();
                                            break;
                                        case 7:
                                            system("cls");
                                            deleteLoop = false;
                                            system("cls");
                                            break;
                                        default:
                                            system("cls");
                                            cout << RED << "Incorrect Input" << RESET << endl;
                                            break;
                                        }
                                    }
                                }
                                break;
                                case 7:
                                    system("cls");
                                    History();
                                    break;
                                case 8:
                                    system("cls");
                                    adminLoop = false;
                                    system("cls");
                                    break;
                                }
                            }
                        }
                        else
                        {
                            setPosition(80, 17);
                            cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
                            cin.ignore();
                            cin.get();
                            system("cls");
                        }
                    }
                    break;
                    case 5:
                        system("cls");
                        Order(list);
                        break;
                    case 6:
                        Exitloop = false;
                        system("cls");
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        break;
        case 2:
            signIn();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
        }
    }
    return 0;
}