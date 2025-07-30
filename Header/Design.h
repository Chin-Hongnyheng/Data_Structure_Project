#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
using namespace std;
#ifndef Design_H
#define Design_H

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define ORANGE "\033[38;5;208m"

// for printing the receipt
bool printed = true;

// for showing the menu
struct Food
{
    int id;
    string name;
    double price;
};

struct Menu
{
    Food food;
    Menu *next;
};

struct Queue
{
    int n;
    Menu *front;
    Menu *rear;
};

Queue *EmptyQueue()
{
    Queue *q = new Queue;
    q->n = 0;
    q->front = nullptr;
    q->rear = nullptr;
    return q;
}
bool isEmpty(Queue *q)
{
    return q->n == 0;
}

void enqueue(Queue *q, Food food)
{
    Menu *m = new Menu;
    m->food.id = food.id;
    m->food.name = food.name;
    m->food.price = food.price;
    m->next = nullptr;
    if (q->n == 0)
    {
        q->front = m;
        q->rear = m;
    }
    else
    {
        q->rear->next = m;
        q->rear = m;
    }
    q->n++;
}
void dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        return;
    }
    Menu *m = q->front;
}

// For receipt and Store Order History
struct Receipt
{
    int id;
    string name;
    double price;
    int quantity;
};
struct Component
{
    Receipt receipt;
    Component *next;
};
struct List
{
    int n;
    Component *head;
    Component *tail;
};
List *EmptyList()
{
    List *ls = new List;
    ls->n = 0;
    ls->head = nullptr;
    ls->tail = nullptr;
    return ls;
}
void add_last(List *ls, Receipt receipt)
{
    Component *e = new Component();
    e->receipt.id = receipt.id;
    e->receipt.name = receipt.name;
    e->receipt.price = receipt.price;
    e->receipt.quantity = receipt.quantity;
    e->next = nullptr;
    if (ls->n == 0)
    {
        ls->head = e;
    }
    else
    {
        ls->tail->next = e;
    }
    ls->tail = e;
    ls->n++;
}
void delete_first(List *ls)
{
    if (ls->n == 0)
    {
        return;
    }
    Component *e = ls->head;
    ls->head = ls->head->next;
    delete e;
    if (ls->n == 1)
    {
        ls->tail = nullptr;
    }
    ls->n--;
}
void delete_last(List *ls)
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
        Component *e = ls->head;
        while (e->next != ls->tail)
        {
            e = e->next;
        }
        e->next = nullptr;
        delete ls->tail;
        ls->tail = e;
    }
}
bool modify_quantity(List *ls, int id, int quantity)
{
    Component *temp = ls->head;
    while (temp != nullptr)
    {
        if (id == temp->receipt.id)
        {
            temp->receipt.quantity = quantity;
            return true;
            break;
        }
    }
    return false;
}
bool search_id(List *ls, int id)
{
    Component *temp = ls->head;
    while (temp != nullptr)
    {
        if (id == temp->receipt.id)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
bool delete_id(List *ls, int id)
{
    Component *temp = ls->head;
    int count = 0;
    int pos = -1;
    while (temp != nullptr)
    {
        if (id == temp->receipt.id)
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
        delete_first(ls);
        ls->n--;
    }
    else if (pos == ls->n - 1)
    {
        delete_last(ls);
        ls->n--;
    }
    else
    {
        Component *current = ls->head;
        for (int i = 0; i < pos - 1; i++)
        {
            current = current->next;
        }
        Component *deleteid = current->next;
        current->next = deleteid->next;
        delete deleteid;
        ls->n--;
    }
    return true;
}

void delete_all(List *ls)
{
    while (ls->n > 0)
    {
        delete_first(ls);
    }
}
// For Password Protection
struct Element
{
    char c;
    Element *next;
};
struct Stack
{
    int n;
    Element *top;
};
Stack *createStack()
{
    Stack *s = new Stack();
    s->n = 0;
    s->top = nullptr;
    return s;
}
void push(Stack *s, char c)
{
    Element *e = new Element();
    e->c = c;
    e->next = s->top;
    s->top = e;
    s->n++;
}
void pop(Stack *s)
{
    Element *e = s->top;
    s->top = e->next;
    delete e;
    s->n--;
}
string convertStackToString(Stack *s)
{
    Element *temp = s->top;
    string output = "";
    while (temp != nullptr)
    {
        output = temp->c + output;
        temp = temp->next;
    }
    return output;
}
string getPassword()
{
    string password;
    char c;
    Stack *stack = createStack();
    while ((c = getch()) != '\r')
    {
        if (c == '\b')
        {
            pop(stack);
            cout << "\b \b";
        }
        else
        {
            push(stack, c);
            cout << '*';
        }
    }
    password = convertStackToString(stack);
    return password;
}
string getDate()
{
    // this function get the total second from epoch (1st january 1970)
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int day = ltm->tm_mday;
    int month = ltm->tm_mon + 1;
    int year = ltm->tm_year + 1900;

    string daystr = to_string(day);
    string monthstr = to_string(month);
    string yearstr = to_string(year);

    string Date = daystr + "/" + monthstr + "/" + yearstr;
    return Date;
}
void setPosition(int x, int y)
{
    // Use SHORT type because COORD Define in this window
    COORD C = {(SHORT)x, (SHORT)y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), C);
}

void loading()
{
    setPosition(75, 4);
    cout << YELLOW << "Loading" << endl;
    char x = 219;
    setPosition(75, 6);
    for (int i = 0; i <= 40; i++)
    {
        cout << YELLOW << x;
        Sleep(50);
    }
    system("cls");
}
void printing()
{
    setPosition(80, 4);
    cout << YELLOW << "Printing Receipt ";
    char x = '.';
    for (int i = 0; i < 3; i++)
    {
        setPosition(97, 4);
        for (int j = 0; j < 5; j++)
        {
            cout << YELLOW << x;
            Sleep(400);
        }
        setPosition(97, 4);
        cout << "     " << flush;
    }
    system("cls");
}
void Title()
{
    string title = "::: WELCOME TO BAYMAK RESTAURANT :::";
    string slogan = "*** WHERE TASTE MEETS EXCELLENCE ***";
    system("cls");
    setPosition(80, 5);
    for (char c : title)
    {
        cout << GREEN << c << RESET << flush;
        Sleep(50);
    }
    cout << endl;
    setPosition(80, 7);
    for (char c : slogan)
    {
        cout << GREEN << c << RESET << flush;
        Sleep(50);
    }
    system("cls");
}
#endif
