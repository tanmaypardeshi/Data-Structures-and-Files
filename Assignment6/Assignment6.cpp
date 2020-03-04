#include<iostream>
#include "user.h"
using namespace std;

int main()
{
	int choice;

	while(1)
	{
		cout<<"\nGraph Operations"<<endl;
		cout<<"1. Find out who is having maximum friends"<<endl;
		cout<<"2. Find out who has posted maximum and minimum comments"<<endl;
		cout<<"3. Find users having birthday this month"<<endl;
		cout<<"4. Exit program"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				return 0;
			default:
				cout<<"\nError in choice, try again"<<endl;
		}
	}
	return 0;
}
