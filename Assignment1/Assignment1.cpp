#include<iostream>
#include "Stack.h"
using namespace std;

int main()
{
	Stack s;
	int choice;

	while(1)
	{
		cout<<"\nStack"<<endl;
		cout<<"1.Push"<<endl;
		cout<<"2.Pop"<<endl;
		cout<<"3.Display"<<endl;
		cout<<"4.Top"<<endl;
		cout<<"5.Reverse"<<endl;
		cout<<"6.Exit"<<endl;
		cout<<"\nEnter choice:- ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				char x;
				cout<<"Enter element to push:- ";
				cin>>x;
				s.push(x);
				cout<<"\nElement "<<x<<" pushed successfully\n";
				break;

			case 2:
				if(s.isempty())
				{
					cout<<"Stack is empty"<<endl;
					break;
				}
				cout<<"Element popped is:- "<<s.pop()<<endl;
				break;

			case 3:
				if(s.isempty())
				{
					cout<<"Stack is empty"<<endl;
					break;
				}
				cout<<"Elements of stack are:- ";
				s.display();
				cout<<endl;
				break;

			case 4:
				if(s.isempty())
				{
					cout<<"Stack is empty"<<endl;
					break;
				}
				cout<<"Top element of stack is:- ";
				cout<<x<<endl;
				break;
			case 5:
				if(s.isempty())
				{
					cout<<"Stack is empty"<<endl;
					break;
				}
				s.reverse();
				cout<<"Linked list reversed successfully"<<endl;
				break;
			case 6:
				return EXIT_SUCCESS;
			default:
				cout<<"Error in choice, try again"<<endl;
		}
	}
	return EXIT_SUCCESS;
}
