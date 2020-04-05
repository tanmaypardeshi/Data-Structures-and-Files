/* 
Assignment 6
Name:- Tanmay Pardeshi
Roll number:- 23260
Batch:- H10
*/

#include <iostream>
#include "users.cpp"
using namespace std;

class Facebook
{
	Graph g;

public:
	void createprofile();
	void displayuser();
	void display();
	void befriend();
	void birthdays();
	void comments();
};

void Facebook::createprofile()
{
	Vertex profile;

	cout << "\nEnter your name:- ";
	cin >> profile.name;
	cout << "\nEnter your birth date(dd<space>mm<space>yyyy):- ";
	cin >> profile.birthdate.dd >> profile.birthdate.mm >> profile.birthdate.yyyy;
	cout << "\nEnter the number of comments you've made:- ";
	cin >> profile.comments;

	g.create_user(profile.name, profile.birthdate.dd, profile.birthdate.mm, profile.birthdate.yyyy, profile.comments);
	cout << "\nProfile created successfully! Welcome to Facebook." << endl;
}

void Facebook::display()
{
	if (g.isempty())
		cout << "\nNo network yet." << endl;

	else
	{
		cout << "\n-------------Facebook USERS-------------" << endl;
		g.display();
		cout << "----------------------------------------" << endl;
	}
}

void Facebook::displayuser()
{
	string user;

	cout << "\nEnter name:- ";
	cin >> user;
	g.displayuser(user);
}

void Facebook::befriend()
{
	string user1, user2;

	cout << "\nEnter the name of user 1:- ";
	cin >> user1;
	cout << "\nEnter the name of user 2:- ";
	cin >> user2;
	g.addfriend(user1, user2);
}

void Facebook::birthdays()
{
	int month;
	char monthc[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	cout << "\nEnter the month:- ";
	cin >> month;
	cout << "\n-----Birthdays in " << monthc[month - 1] << "-----" << endl;
	g.dfs(month);
	cout << "----------------------------" << endl;
}

void Facebook::comments()
{
	g.bfs();
}

int main()
{
	int choice, data;
	Facebook f;

	while (1)
	{
		cout << "\nDFS and BFS" << endl;
		cout << "1. Create new user" << endl;
		cout << "2. Display all user names" << endl;
		cout << "3. Add Friends" << endl;
		cout << "4. View a user's  profile" << endl;
		cout << "5. Get maximum and minimum comments" << endl;
		cout << "6. Check for birthdays" << endl;
		cout << "7. Exit program" << endl;
		cout << "\nEnter your choice:- ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			f.createprofile();
			break;
		case 2:
			f.display();
			break;
		case 3:
			f.befriend();
			break;
		case 4:
			f.displayuser();
			break;
		case 5:
			f.comments();
			break;
		case 6:
			f.birthdays();
			break;
		case 7:
			return 0;
		default:
			cout << "\nError in choice, try again" << endl;
		}
	}
	return 0;
}