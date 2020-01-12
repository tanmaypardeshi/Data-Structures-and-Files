/* 
Assignment 2
Name:- Tanmay Pardeshi
Roll number:- 23260
Batch:- H10
*/

#include "Queue.h"
#include<iostream>
#include<iomanip>

namespace std
{
	template <class T>
	Queue<T>::Queue() 
	{
		front=rear=NULL;
	}

	template <class T>
	void Queue<T>::addq(T data)
	{
		node<T> *newnode;
		newnode = new node<T>;
		newnode->data=data;
		newnode->next= NULL;

		if(isqempty())
		{
			front=newnode;
			rear=newnode;
		}
		else
		{
			rear->next=newnode;
			rear=newnode;
		}
	}

	template <class T>
	void Queue<T>::delq()
	{

		int priority1,priority2;
		node<T> *temp1,*temp2;
		T patient_data;
		temp1=front;
		temp2=front;
		if(front==NULL)
			cout<<"Queue is empty!\nPlease add patients in queue first";
		else
		{
			priority1=temp1->data.priority;
			while(temp1!=NULL)
			{
				priority2=temp1->data.priority;
				if(priority2>priority1)
					priority1=priority2;
				temp1=temp1->next;
			}
		
			temp1=front;
			while(priority1!=temp1->data.priority)
				temp1=temp1->next;
		
			if(temp1==front)
				front=temp1->next;
			else
			{
				while(temp2->next!=temp1)
					temp2=temp2->next;
				temp2->next=temp1->next;
				if(temp1==rear)
					rear=temp2;
			}
			cout<<"\n\nPatient Served\n";
			cout<<"Patient Details:-";
			cout<<"\nNAME:- "<<temp1->data.name;
			cout<<"\nID:- "<<temp1->data.id;
			cout<<"\nBLOOD GROUP:- "<<temp1->data.bloodgroup;
			cout<<"\nILLNESS:- "<<temp1->data.disease<<"\n"<<endl;
			delete temp1;
			
		}
	}

	template <class T>
	int Queue<T>::isqempty()
	{
		if(front==NULL)
			return 1;
		return 0;
	}


	template <class T>
	void Queue<T>::displayq()
	{
		int i=1;
		node<T> *temp;
		temp=front;
		if(front==NULL)
		{
			cout<<"Queue is empty!\nPlease add patients in queue first";
			return;
		}
		cout<<"\n\n-------------------------------------------------------";
		cout<<"-------------------------------\n";
		cout<<setw(7)<<"Sr.No."<<setw(8)<<"ID"<<setw(10)<<"Name"<<setw(13)<<"Illness";
		cout<<setw(18)<<"Blood Group"<<setw(20)<<"Contact Number";
		cout<<"\n----------------------------------------------------------";
		cout<<"----------------------------\n";
		
		while(temp!=NULL)

		{
			cout<<setw(5)<<i<<setw(10)<<temp->data.id<<setw(12);
			cout<<temp->data.name<<setw(13)<<temp->data.disease<<setw(11);
			cout<<temp->data.bloodgroup<<setw(18)<<temp->data.mobile<<endl;
			temp=temp->next;
			i++;
		}
	}
}
