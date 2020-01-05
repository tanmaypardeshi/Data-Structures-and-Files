#include<iostream>
#include "Stack.h"
using namespace std;

template <class T>
Stack<T>::Stack()
{
	top=NULL;
}

template <class T>
void Stack<T>::push(T x)
{
	Node *newnode;
	newnode=new Node;

	newnode->data=x;
	newnode->next=top;
	top=newnode;
}

template <class T>
T Stack<T>::pop()
{
	T x;
	Node *temp;
	temp=top;
	x=temp->data;
	top=top->next;
	delete temp;
	return x;
}

template <class T>
T Stack<T>::topelement()
{
	return top->data;
}

template <class T>
int Stack<T>::isempty()
{
	if(top==NULL)
		return 1;
	return 0;
}

template <class T>
void Stack<T>::reverse()
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

template <class T>
void Stack<T>::display()
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
