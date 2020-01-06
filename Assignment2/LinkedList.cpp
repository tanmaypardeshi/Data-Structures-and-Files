#include<iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	head=NULL;
}

void LinkedList::insert(int data,int pos)
{
	Node *current=new Node;
	Node *temp;
	current->data=data;
	current->next=NULL;
	
	if(head==NULL)
	{
		current->next=NULL;
		head=current;
		temp=current;
	}
	else
	{
		if(pos==1)
		{
			current->next=head;
			head=current;
			temp=current;
		}
		else
		{
			for(int i=0;i<pos-1;i++)
				temp=temp->next;
			
			current->next=temp->next;
			temp->next=current;
		}
	}	
}

int LinkedList::deletenode(int pos)
{
	Node *current,*temp;
	int data;
	
	if(pos==1)
	{
		current=head;
		head=head->next;
	}
	else
	{
		temp=head;
		for(int i=0;i<pos-1;i++)
			temp=temp->next;
	
		current=temp->next;
		temp->next=current->next;
	}
	
	data=current->data;
	delete(current);
	
	return data;
}

void LinkedList::display()
{
	Node *temp=head;
	
	while(temp!=NULL)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
