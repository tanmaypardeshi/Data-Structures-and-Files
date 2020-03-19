#include <iostream>
#include <iomanip>
#define SIZE 50
using namespace std;

struct Node
{
    long number;
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
    void woreplacement(long, string);
    void wreplacement(long, string);
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

void HashTable::woreplacement(long number, string name)
{
    int location;
    int i = 0;

    location = number % size;
    int j = location;

    if (!h[location].flag)
    {
        h[location].name = name;
        h[location].number = number;
        h[location].flag = true;
    }
    else
    {
        while (h[j].flag && i < size)
        {
            if (h[j].number % size == number % size)
                break;
            j = (j + 1) % size;
            i++;
        }
        if (i == size)
        {
            cout << "\nHash Table is full\n";
            return;
        }
        h[location].chain = j;
        location = j;
        h[location].flag = true;
        h[location].number = number;
        h[location].name = name;
    }
}

void HashTable::wreplacement(long number, string name)
{

    int location, oldlocation, i, j, flag = 0;
    Node temp;
    location = number % size;
    i = 0;
    j = location;

    if (!h[location].flag)
    {
        h[location].flag = true;
        h[location].number = number;
        h[location].name = name;
    }

    else
    {
        if (h[location].number % size != location)
        {
            temp.name = h[location].name;
            temp.number = h[location].number;
            temp.flag = true;
            temp.chain = h[location].chain;

            h[location].name = name;
            h[location].number = number;
            h[location].chain = -1;

            name = temp.name;
            number = temp.number;
            oldlocation = location;
            flag = true;
        }

        while (h[j].flag && i < size)
        {
            if (h[j].number % size == number % size)
                break;
            j = (j + 1) % size;
            i++;
        }
        if (i == size)
        {
            cout << "\nTable is full." << endl;
            return;
        }

        if (!flag)
            h[location].chain = j;
        location = j;
        h[location].flag = 1;
        h[location].number = number;
        h[location].name = name;

        for (int i = 0; i < size; i++)
            if (h[i].chain == oldlocation)
            {
                h[i].chain = location;
                break;
            }
    }
}

void HashTable::display()
{
    cout << "---------------------------------------";
    ;
    cout << "---------------------------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << setw(10) << h[i].name << setw(25) << h[i].number << setw(28) << h[i].chain << endl;
    }
}

int main()
{
    char ask = 'y';
    int n;
    cout << "Enter the size of the hashtable:- ";
    cin >> n;

    HashTable h(n);
    int cntr = 0;
    while ((ask == 'y' || ask == 'Y') && cntr < n)
    {
        cout << "\nEnter name:- ";
        string name;
        cin >> name;
        cout << "Enter the mobile number:- ";
        int number;
        cin >> number;
        h.wreplacement(number, name);
        cntr++;
        cout << "Do you want to continue:- ";
        cin >> ask;
    }
    h.display();
}