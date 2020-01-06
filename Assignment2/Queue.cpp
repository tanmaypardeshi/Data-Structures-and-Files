#include<iostream>
#include "Queue.h"
using namespace std;


Queue::Queue()
{
	front = NULL;
	rear = NULL;
}

void enqueue(int data)
{
	rear.insert();
	if(front==NULL)
		front=front->next;
}


int delq(struct queue q[])
{
	int max;
	Node *temp=front;
	while(temp!=rear)
	{
		if (temp->flag == NULL)
		{
			max = temp->data;
			break;
		}
		temp=temp->next;
	}
	temp=front;
	while(temp!=rear)
	{
		if (temp->flag == 0 && max < temp->data)
		{
			max = temp->data;
		}
		temp=temp->next;
	}
	temp->flag = 1;
	return max;
}


void display()
{
	LinkedList *temp=front;
	while(temp!=rear)
	{
		if (temp->flag == 0)
			cout<<temp->data;
		temp=temp->next;
	}	
}

int isqempty()
{
	if (front == NULL)
		return 1;
	return 0;
}



