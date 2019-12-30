//Stack

#include<iostream>
#include "Stack.h"
using namespace std;


Stack::Stack()
{
	top=NULL;
}


void Stack::push(char x)
{
	Node *newnode;
	newnode=new Node;

	newnode->data=x;
	newnode->next=top;
	top=newnode;
}

char Stack::pop()
{
	char x;
	Node *temp;
	temp=top;
	x=temp->data;
	top=top->next;
	delete temp;
	return x;
}

char Stack::topelement()
{
	return top->data;
}


char Stack::isempty()
{
	if(top==NULL)
		return 1;
	return 0;
}

void Stack::reverse()
{
	Node *prev,*current;

	if(top!=NULL)
	{
		prev=top;
		top=top->next;
		current=top;
		prev->next=NULL;

		while(top!=NULL)
		{
			top=top->next;
			current->next=prev;
			prev=current;
			current=top;
		}
	}
	top=prev;
}

void Stack::display()
{
	Node *temp;
	temp=top;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<"\n";
}
