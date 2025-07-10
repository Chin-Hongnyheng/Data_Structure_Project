#include <iostream>
#include "Design.h"
#include <conio.h>
#include <fstream>
#include "Login.h"
using namespace std;
#ifndef SIGNIN_h
#define SIGNIN_h

void signIn()
{
    system("cls");
    setPosition(80, 5);
    cout << YELLOW << "::: Sign in For a new Account ::::" << RESET << endl;

    setPosition(80, 7);
    cout << YELLOW << "New UserName: " << RESET;
    string userName;
    cin >> userName;

    setPosition(80, 8);
    cout << YELLOW << "Email: " << RESET;
    string email;
    cin >> email;
    setPosition(80, 9);

    cout << YELLOW << "Age: " << RESET;
    int age;
    cin >> age;
    setPosition(80, 10);

    cout << YELLOW << "Gender: " << RESET;
    string gender;
    cin >> gender;
    setPosition(80, 11);

    cout << YELLOW << "Password: " << RESET;
    string password;
    password = getPassword();
    setPosition(80, 12);

    cout << YELLOW << "Confirm Password: " << RESET;
    string confirmPassword;
    confirmPassword = getPassword();

    cin.clear();

    if (password == confirmPassword)
    {
        ofstream File;
        File.open("Data/Customer.csv", ios::app);
        if (!File.is_open())
        {
            return;
        }
        else
        {
            File << userName << "," << email << "," << age << "," << gender << "," << password << endl;
            File.close();
            setPosition(80, 14);
            cout << GREEN << "Sign Up Successfully" << RESET << endl;
            setPosition(80, 15);
            setPosition(80, 16);
            cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
            cin.ignore();
            cin.get();
            system("cls");
        }
    }
    else
    {
        setPosition(80, 14);
        cout << RED << "Failed to Sign in" << RESET << endl;
        cout << YELLOW << "Press ENTER to continue..." << RESET << endl;
        cin.ignore();
        cin.get();
        system("cls");
    }
}
#endif