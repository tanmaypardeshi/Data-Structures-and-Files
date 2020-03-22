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

    for (int i = 0; i < size; i++)
    {
        h[i].flag = false;
        h[i].chain = -1;
    }
    for (int k = 0; k < size; k++)
    {
        location = number % size;
        i = 0;

        if (h[location].flag == false)
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
}

void HashTable::display()
{
    cout << "--------------------------------------------------------------------" << endl;
    cout << "\nSr.no\tName\tTelephone\t\tChain" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << "\t" << h[i].name << "\t" << h[i].number << "\t\t" << h[i].chain << endl;
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
    HashTable t(size);

    while (1)
    {
        cout << "\nLinear Probing in hash table" << endl;
        cout << "1. Insert with chaining without replacement." << endl;
        cout << "2. Insert with chaining with replacement." << endl;
        cout << "3. Exit program." << endl;
        cout << "\nEnter your choice:- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the name:- ";
            cin >> name;
            cout << "Enter the number:- ";
            cin >> number;
            t.woreplacement(number, name);
            t.display();
            break;
        case 2:
            cout << "Enter the name:- ";
            cin >> name;
            cout << "Enter the number:- ";
            cin >> number;
            t.wreplacement(number, name);
            t.display();
            break;
        case 3:
            return 0;
        }
    }
    return 0;
}