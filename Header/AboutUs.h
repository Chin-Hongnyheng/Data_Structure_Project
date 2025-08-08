#include <iostream>
#include "Design.h"
using namespace std;
#ifndef ABOUT_US_H
#define ABOUT_US_H
void DisplayAboutUs()
{
    setPosition(0, 3);
    cout << GREEN << "::Restaurant Management System::" << endl;
    setPosition(0, 4);
    cout << "C++ Project By Group 5" << endl;
    setPosition(0, 6);
    cout << "Restaurant Management Program System implement with the Data Structure {Linked List, Queue, Map, Stack}" << endl;
    setPosition(0, 7);
    cout << "CRUD Implemented Throughout the program" << endl;
    setPosition(0, 9);
    cout << "NOTE: This Program only save the data once the receipt is printed." << endl;
    setPosition(0, 10);
    cout << "User can Modify their Order in Order History" << endl;
    setPosition(0, 12);
    cout << "Account for Admin: " << endl;
    setPosition(0, 13);
    cout << "Username: admin" << endl;
    setPosition(0, 14);
    cout << "Password: admin1123" << endl;
    setPosition(0, 16);
    cout << "Contribution: " << endl;
    setPosition(0, 17);
    cout << "Develop Admin Panel: Chin Hongnyheng" << endl;
    setPosition(0, 18);
    cout << "Cart Developer: Noch MunnyRatanak" << endl;
    setPosition(0, 19);
    cout << "Menu : Vireak Rith" << endl;
    setPosition(0, 20);
    cout << "Registration: Pon PolPrachnha" << endl;
    setPosition(0, 23);
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
}
#endif