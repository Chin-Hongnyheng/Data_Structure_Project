#include <iostream>
#include "Design.h"
using namespace std;
#ifndef DESCRIPTION_H
#define DESCRIPTION_H
void DisplayDescription()
{
    setPosition(0, 3);
    cout << GREEN << "Description: HOW TO USE OUR PROGRAM?" << endl;
    setPosition(0, 5);
    cout << "First Panel: Account" << endl;
    setPosition(0, 6);
    cout << "Click Sign Up To Create a new Account." << endl;
    setPosition(0, 7);
    cout << "Already Have An Account? -> Click Login" << endl;
    setPosition(0, 8);
    cout << "Program Information? -> Click About Us" << endl;
    setPosition(0, 10);
    cout << "Second Panel: " << endl;
    setPosition(0, 11);
    cout << "Place An Order? -> Login -> Place An Order -> Select Any Categories" << endl;
    setPosition(0, 12);
    cout << "Access Admin Panel? -> About Us (admin account) -> Login -> Admin Panel" << endl;
    setPosition(0, 13);
    cout << "Modify Your Order? -> Click Order History" << endl;
    setPosition(0, 14);
    cout << "Change An Account? -> Click Logout -> Login" << endl;
    setPosition(0, 16);
    cout << "NOTE: Once You Confirm Your Order The Recept is Printed." << endl;
    setPosition(0, 17);
    cout << "Read Carefully To Avoid Any Confusion." << endl;
    setPosition(0, 18);
    cout << "Input the Terminal In Full Screen To See Full Feature." << RESET << endl;
    setPosition(0, 20);
    cout << YELLOW << "PRESS Enter to continue..." << RESET << endl;
    cin.ignore();
    cin.get();
    system("cls");
}
#endif