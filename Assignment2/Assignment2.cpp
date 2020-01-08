#include<iostream>
#include "Queue.cpp"
#define SIZE 60
using namespace std;


class Patient
{
	Queue q;
	
	public:
		void enter();
		void remove();
		void list();
};

void Patient::enter()
{
	q.addq();
}

void Patient::remove()
{
	q.delq();
}

void Patient::list()
{
	q.displayq();
}


int main()
{
	int choice;
	Patient p;
	
	while(1)
	{
		cout<<"\nHospital Management System"<<endl;
		cout<<"1. Enter patient details"<<endl;
		cout<<"2. Allocate patient for treatment"<<endl;
		cout<<"3. List all the patients"<<endl;
		cout<<"4. Exit the program"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				p.enter();
				cout<<"Details of patient entered successfully"<<endl;
				break;
			case 2:
				p.remove();
				break;
			case 3:
				p.list();
				break;
			case 4:
				return 0;
			default:
				cout<<"Error in choice, try again"<<endl;
		}
	}
}
