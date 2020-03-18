#include <iostream>
#include <fstream>
#include <iomanip>
#define SIZE 100
using namespace std;

class Student
{
private:
    int rollno;
    int marks;
    char name[SIZE];

public:
    void accept();
    void display();
    void modify();
    int getrno();
};

void Student::accept()
{
    cout << "Enter the roll number:- ";
    cin >> rollno;
    cin.ignore();
    cout << "Enter the name of the student:- ";
    cin.getline(name, SIZE);
    cout << "Enter the marks:- ";
    cin >> marks;
}

void Student::display()
{
    cout << "\t" << rollno << "\t   " << name << "   \t" << marks << "\n";
}

void Student::modify()
{
    cin.ignore();
    cout << "Enter new name of student:- ";
    cin.getline(name, SIZE);
    cout << "Enter the new marks:- ";
    cin >> marks;
}

int Student::getrno()
{
    return rollno;
}

int create(int);
void display(int);
int add(int);
void deleterec(int);
void modifyrec(int);

int main()
{
    int choice, i, flag, cntr = 0;

    while (1)
    {
        cout << "\nStudents Database" << endl;
        cout << "1. Create" << endl;
        cout << "2. Display" << endl;
        cout << "3. Add" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Modify" << endl;
        cout << "6. Exit program" << endl;
        cout << "\nEnter your choice:- ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cntr = create(cntr);
            break;
        }

        case 2:
        {
            display(cntr);
            break;
        }
        case 3:
        {
            if (cntr == 0)
                cout << "\nPlease build a master table first" << endl;
            else
                cntr = add(cntr);
            break;
        }

        case 4:
        {
            if (cntr == 0)
                cout << "\nPlease build a master table first" << endl;
            else
                deleterec(cntr);
            break;
        }
        case 5:
        {
            if (cntr == 0)
                cout << "\nPlease build a master table first" << endl;
            else
                modifyrec(cntr);
            break;
        }
        case 6:
            return 0;
        default:
            cout << "Error in choice,try again" << endl;
        }
    }
    return 0;
}

int create(int cntr)
{
    int rno;
    Student m;
    ofstream fout("recs.dat", ios::binary | ios::out);
    cntr = 0;
    char ask = 'y';
    while (ask == 'y' || ask == 'Y')
    {
        m.accept();
        fout.write((char *)&m, sizeof(m));
        cntr++;
        cout << "\nDo you want to add another record?(y/n):- ";
        cin >> ask;
    }
    fout.close();
    return cntr;
}

void display(int cntr)
{
    int i;
    Student m;
    if (cntr == 0)
        cout << "\nPlease build a master table first" << endl;
    else
    {
        ifstream fin("recs.dat", ios::binary | ios::in);
        cout << "\n-----------------------------------------------------------------" << endl;
        cout << "Sr No. " << setw(5) << "Roll No.  ";
        cout << "  Name  ";
        cout << "     Marks" << endl;
        cout << "\n-----------------------------------------------------------------" << endl;
        i = 1;
        while (fin.read((char *)&m, sizeof(m)))
        {
            cout << "  " << i << "  ";
            m.display();
            i++;
        }
        fin.close();
    }
}

int add(int cntr)
{
    Student m;
    ofstream fout("recs.dat", ios::binary | ios::app);
    cout << "Enter the details of the record you want to insert:- " << endl;
    m.accept();
    fout.write((char *)&m, sizeof(m));
    fout.close();
    cntr++;
    cout << "Record inserted successfully" << endl;
    return cntr;
}

void deleterec(int cntr)
{
    Student m;
    int flag;
    int rno;
    ifstream fin("recs.dat", ios::binary | ios::in);
    cout << "Enter the roll number of the record you want to delete:- ";
    cin >> rno;
    flag = 0;
    while (fin.read((char *)&m, sizeof(m)))
    {
        if (rno == m.getrno())
        {
            flag = 1;
            cntr--;
            break;
        }
    }
    fin.close();
    if (!flag)
        cout << "\nRecord with roll number " << rno << " not found" << endl;
    else
    {
        ofstream fout("temp.dat", ios::binary | ios::out);
        ifstream fin("recs.dat", ios::binary | ios::out);
        fin.seekg(0, ios::beg);
        fin.read((char *)&m, sizeof(m));
        while (!fin.eof())
        {
            if (m.getrno() != rno)
                fout.write((char *)&m, sizeof(m));
            fin.read((char *)&m, sizeof(m));
        }
        fout.close();
        fin.close();
        cout << "Record with roll number " << rno << " deleted successfully" << endl;
        remove("recs.dat");
        rename("temp.dat", "recs.dat");
    }
}

void modifyrec(int cntr)
{
    Student m;
    int rno;
    int flag;
    ifstream fin("recs.dat", ios::binary | ios::in);
    cout << "Enter the roll number of the record you want to edit:- ";
    cin >> rno;
    flag = 0;
    while (fin.read((char *)&m, sizeof(m)))
    {
        if (rno == m.getrno())
        {
            flag = 1;
            cntr--;
            break;
        }
    }
    fin.close();
    if (!flag)
        cout << "\nRecord with roll number " << rno << " not found" << endl;
    else
    {
        ofstream fout("temp.dat", ios::binary | ios::out);
        ifstream fin("recs.dat", ios::binary | ios::out);
        fin.read((char *)&m, sizeof(m));
        while (!fin.eof())
        {
            if (m.getrno() == rno)
            {
                m.modify();
                fout.write((char *)&m, sizeof(m));
            }
            else
                fout.write((char *)&m, sizeof(m));
            fin.read((char *)&m, sizeof(m));
        }
        fout.close();
        fin.close();
        cout << "Record with roll number " << rno << " edited successfully" << endl;
        remove("recs.dat");
        rename("temp.dat", "recs.dat");
    }
}