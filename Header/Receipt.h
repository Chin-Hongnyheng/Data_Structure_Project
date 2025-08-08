#include <iostream>
#include "Design.h"
#include <iomanip>
using namespace std;
#ifndef RECEIPT_H
#define RECEIPT_H
string Name;
// using Linked List from Design.h
int ReceiptPaper(List *ls)
{
    // Global boolean from Design.h
    printed = false;
    setPosition(82, 5);
    cout << GREEN << ":::: BAYMAK Restaurant ::::" << endl;
    setPosition(70, 6);
    cout << "---------------------------------------------------" << endl;
    setPosition(70, 7);
    cout << "|";
    setPosition(83, 7);
    cout << "Order Receipt NO:********" << endl;
    setPosition(120, 7);
    cout << "|" << endl;
    setPosition(70, 8);
    cout << "| Customer: " << Name;
    setPosition(120, 8);
    cout << "|" << endl;
    setPosition(70, 9);
    cout << "---------------------------------------------------" << endl;
    setPosition(70, 10);
    cout << "| # Item";
    setPosition(103, 10);
    cout << "Qty";
    setPosition(114, 10);
    cout << "Price |" << endl;
    setPosition(70, 11);
    cout << "---------------------------------------------------" << RESET << endl;
    Component *temp = ls->head;
    double total = 0;
    int y = 12;
    while (temp != nullptr)
    {
        int amount = temp->receipt.quantity;
        double price = temp->receipt.price * amount;
        setPosition(70, y);
        cout << GREEN << "|";
        setPosition(71, y);
        cout << fixed << setw(2) << temp->receipt.id;
        setPosition(74, y);
        cout << temp->receipt.name;
        setPosition(104, y);
        cout << temp->receipt.quantity;
        setPosition(113, y);
        cout << fixed << setw(6) << setprecision(2) << setw(5) << price << " $|" << RESET << endl;
        temp = temp->next;
        total += price;
        y++;
    }
    setPosition(70, y);
    cout << GREEN << "---------------------------------------------------" << endl;
    y = y + 1;
    setPosition(70, y);
    cout << "| Total: " << total << " $" << endl;
    setPosition(120, y);
    cout << "|" << endl;
    y = y + 1;
    setPosition(70, y);
    cout << "---------------------------------------------------" << endl;
    return y;
}
void Display(List *ls)
{
    int y = ReceiptPaper(ls);
    setPosition(72, y + 3);
    cout << "Thank you for your order! Please visit us again" << RESET << endl;
}
void SaveHistory(List *ls)
{
    ofstream output;
    output.open("Data/History.csv", ios::app);
    if (!output.is_open())
    {
        return;
    }
    Component *temp = ls->head;
    while (temp != nullptr)
    {
        double price = temp->receipt.price * temp->receipt.quantity;
        output << temp->receipt.id << ',' << temp->receipt.name << ',' << temp->receipt.quantity << ',' << price << ',' << getDate() << endl;
        temp = temp->next;
    }
    output.close();
}
#endif