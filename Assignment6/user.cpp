#include<iostream>
#include<string.h>
#include "user.h"
#define MAX 100
using namespace std;

Node1::Node1(int i)
{
	id=i;
	next=NULL;
}

Node2::Node2(int i)
{
	id=i;
	cin.ignore();
	cout<<"Enter the name:- ";
	cin.getline(name,MAX);
	cout<<"Enter date of birth:- "<<endl;
	cout<<"Enter day:- ";
	cin>>db.dd;
	cout<<"Enter month:- ";
	cin>>db.mm;
	cout<<"Enter year:- ";
	cin>>db.yyyy;
	cout<<"Enter number of comments:- ";
	cin>>comments;
	down=NULL;
	next=NULL;

}

void Graph::create()
{
	int users,index=0;
	cout<<"Enter the total number of users:- ";
	cin>>users;
	if(users!=0)
	{
		cout<<"Enter data for the user:- "<<endl;
		head = new Node2(index);
		index++;
		Node2 *temp=head;
		for(int i=0;i<users;i++)
		{
			cout<<"Enter data for user:- "<<endl;
			temp->down = new Node2(index);
			temp=temp->down;
			index++;
		}
	}
}

int Graph::getindex(char temp[])
{
	Node2 *t=head;

	while(temp!=NULL)
	{
		if(strcmp(t->name,temp)==0)
			return t->id;
		t=t->down;
	}
	return -1;
}

void Graph::addfriends()
{
	char user1[MAX],user2[MAX];
	Node2* temp;

	while(1)
	{
		cin.ignore();
		cout<<"\nEnter the username1 or stop/STOP to stop:- ";
		cin.getline(user1,MAX);

		if(strcmp(user1,"STOP")==0)
			return;

		cout<<"\nEnter the username2 to add a friend:- ";
		cin.getline(user2,MAX);

		temp=head;

		while(temp!=NULL)
		{
			if(temp->id==getindex(user1))
			{
				if(temp->next==NULL)
					temp->next = new Node1(getindex(user2));
				else
				{
					Node1* n = temp->next;
					while(n->next!=NULL)
						n=n->next;
					n->next = new Node1(getindex(user2));
				}
			}
			if(temp->id==getindex(user2))
			{
				if(temp->next==NULL)
					temp->next = new Node1(getindex(user1));
				else
				{
					Node1* m = temp->next;
					while(m->next!=NULL)
						m=m->next;
					m->next = new Node1(getindex(user1));
				}
			}
			temp=temp->down;
		}
	}
}

Node2* Graph::getnode(char temp[])
{
	Node2 *t= head;
	while(t!=NULL)
	{
		if(strcmp(t->name,temp))
			return t;
		t=t->down;

	}
	return NULL;

}


void Graph::show()
{
	Node2 *temp=head;

	while(temp!=NULL)
	{
		cout<<temp->id<<" - "<<temp->name;
		temp->down;
	}
}



