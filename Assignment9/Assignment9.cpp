#include <iostream>
#include <iomanip>
#define SIZE 50
using namespace std;

struct Node
{
    long long number;
    string name;
    bool flag;
    int chain;
};

class HashTable
{
    Node *h;
    int size;

public:
    HashTable() {}
    HashTable(int);
    void woreplacement(long long, string);
    void wreplacement(long long, string);
    void display();
};

HashTable::HashTable(int n)
{
    size = n;

    h = new Node[size];

    for (int i = 0; i < n; i++)
    {
        h[i].number = 0;
        h[i].name = "";
        h[i].flag = false;
        h[i].chain = -1;
    }

    cout << "\nHashtable created successfully!" << endl;
}

void HashTable::woreplacement(long long number, string name)
{
    int i = 0, j, location;

    location = number % size;
    j = location;

    while (h[j].flag && i < size)
    {
        if (h[j].number % size == number % size)
            break;
        j = (j + 1) % size;
        i++;
    }

    if (i == size)
    {
        cout << "\nHash table is full" << endl;
        return;
    }
    while (h[j].chain != -1)
        j = h[j].chain;

    location = j;

    while (h[location].flag && i < size)
    {
        location = (location + 1) % size;
        i++;
    }
    if (i == size)
    {
        cout << "\nHash table is full" << endl;
        return;
    }

    h[location].number = number;
    h[location].name = name;
    h[location].flag = true;

    if (j != location)
        h[j].chain = location;
}

void HashTable::wreplacement(long long number, string name)
{
    int location;
    int i, j;
    location = number % size;
    i = 0;

    if (!h[location].flag)
    {
        h[location].number = number;
        h[location].name = name;
        h[location].flag = true;
    }
    else
    {
        i = 0;
        j = location;
        while (i < size && h[j].flag)
        {
            j = (j + 1) % size;
            i++;
        }

        if (i == size)
        {
            cout << "\nHashtable is full";
            return;
        }

        if (h[location].number % size != location)
        {
            i = h[location].number % size;
            while (h[i].chain != location)
                i = h[i].chain;
            h[i].chain = h[location].chain;

            while (h[i].chain != -1)
                i = h[i].chain;
            h[i].chain = j;

            h[j].number = h[location].number;
            h[j].name = h[location].name;
            h[j].flag = true;
            h[j].chain = -1;

            h[location].number = number;
            h[location].name = name;
            h[location].flag = true;
            h[location].chain = -1;
        }
        else
        {
            h[j].number = number;
            h[j].name = name;
            h[j].flag = true;
            h[j].chain = -1;

            i = location;
            while (h[i].chain != -1)
                i = h[i].chain;
            h[i].chain = j;
        }
    }
}

void HashTable::display()
{
    cout << "--------------------------------------------------------------------" << endl;
    cout << "\nSr.no\tName\t   Telephone\tChain" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << setw(3) << i + 1 << setw(10) << h[i].name << setw(15) << h[i].number << setw(10) << h[i].chain << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;
}

int main()
{
    int choice, size;
    string name;
    long long number;

    cout << "Enter the size of the hash table:- ";
    cin >> size;
    HashTable t1(size);
    HashTable t2(size);

    while (1)
    {
        cout << "\nLinear Probing in hash table" << endl;
        cout << "1. Insert with chaining without replacement." << endl;
        cout << "2. Insert with chaining with replacement." << endl;
        cout << "3. Display table having chaining without replacemment" << endl;
        cout << "4. Display table having chaining with replacement" << endl;
        cout << "5. Exit program." << endl;
        cout << "\nEnter your choice:- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the name:- ";
            cin >> name;
            cout << "Enter the number:- ";
            cin >> number;
            t1.woreplacement(number, name);
            cout << "Inserted successfully" << endl;
            break;
        case 2:
            cout << "Enter the name:- ";
            cin >> name;
            cout << "Enter the number:- ";
            cin >> number;
            t2.wreplacement(number, name);
            cout << "Inserted successfully" << endl;
            break;
        case 3:
            t1.display();
            break;
        case 4:
            t2.display();
            break;
        case 5:
            return 0;
        default:
            cout << "\nError in choice, try again" << endl;
        }
    }
    return 0;
}