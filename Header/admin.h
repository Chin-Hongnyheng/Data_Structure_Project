#include <iostream>
#include <sstream>
#include <fstream>
#include "Design.h"
#ifndef ADMIN_H
#define ADMIN_H
string userName;
string userPassword;
bool verifyAdmin()
{
    ifstream File;
    bool found = false;
    string line;
    File.open("Data/admin.txt");
    if (!File.is_open())
    {
        setPosition(80, 19);
        cout << RED << "File Cannot Open!!" << RESET << endl;
        return false;
    }
    else
    {
        while (getline(File, line))
        {
            stringstream getAdmin(line);
            string adminName, adminPassword;

            getline(getAdmin, adminName, ',');
            getline(getAdmin, adminPassword, ',');
            if (userName == adminName && userPassword == adminPassword)
            {
                return true;
            }
        }
    }
    if (!found)
    {
    }
    setPosition(80, 16);
    cout << RED << "This Panel for ADMIN Only" << RESET << endl;
    return false;
}
#endif