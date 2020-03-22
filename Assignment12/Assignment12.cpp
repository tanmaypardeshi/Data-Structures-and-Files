#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 50
using namespace std;

struct Student
{
    int rollno;
    string name;
    float marks1, marks2, marks3;
    int status;
    int chain;
};

class Database
{
    int size;

public:
    Database();
    int hash(int);
    void displayall();
    void insert();
    void deleterec();
    int search();
    void display(int);
    void read();
    void write();
};

Database::Database()
{
    Student record;
    cout << "Enter size of the table:- ";
    cin >> size;

    fstream file;

    record.rollno = -1;
    record.name = "";
    record.marks1 = record.marks2 = record.marks3 = 0;
    record.status = 1;
    record.chain = -1;

    file.open("recs.dat", ios::binary | ios::out);

    for (int i = 0; i < size; i++)
        file.write((char *)&record, sizeof(record));

    file.close();
}

int Database::hash(int key)
{
    return key % size;
}

void Database::displayall()
{
    cout << "\nDatabase of students\n";
    for (int i = 0; i < size; i++)
        display(i);
}