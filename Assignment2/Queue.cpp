#include<iostream>
#include "Queue.h"
#define SIZE 60
using namespace std;


Queue::Queue()
{
	front = rear = NULL;
}

void Queue::addq()
{
	Node *newnode=new Node;
	Node *temp;
	cout<<"Enter the name of the patient:- ";
	cin.ignore();
	cin.getline(newnode->name,SIZE);
	cout<<"Enter the age of the patient:- ";
	cin>>newnode->age;
	cout<<"Priority 1:- General"<<endl;
	cout<<"Priority 2:- Medium"<<endl;
	cout<<"Priority 3:- Serious"<<endl;
	cout<<"Enter the priority of the disease:- ";
	cin>>newnode->priority;
	newnode->next=NULL;
	if(front==NULL)
	{
		front=temp;
		rear=temp;
	}
	else if(newnode->priority>front->priority)
	{
		newnode->next=front;
		front=newnode;
	}
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			if(newnode->priority<=temp->priority)
				temp=temp->next;
		}
		newnode->next=temp->next;
		temp->next=newnode;
	}
}


void Queue::delq()
{
	Node *temp;
	temp=front;
	front=front->next;
	delete front;
	cout<<"Details of patient:- "<<endl;
	cout<<"Name:- "<<temp->name<<endl;
	cout<<"Age:- "<<temp->age<<endl;
	cout<<"Priority of disease:- "<<temp->priority<<endl;
	return;
}


void Queue::displayq()
{
	Node *temp;
	cout<<"Name\tAge\tPriority"<<endl;
	while(temp!=NULL)
	{
		cout<<temp->name;
		cout<<temp->age;
		cout<<temp->priority;
		cout<<endl;
		temp=temp->next;
	}	
}

int Queue::isempty()
{
	if (front == NULL)
		return 1;
	return 0;
}



