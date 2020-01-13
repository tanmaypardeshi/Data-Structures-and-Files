/* 
Assignment 3
Name:- Tanmay Pardeshi
Roll number:- 23260
Batch:- H10
*/


#include<iostream>
using namespace std;

struct Node
{
	int data;
	Node *left,*right;
};


class BinaryTree
{
	Node *root;
	
	public:
		BinaryTree();
		void insert();
		int isempty();
		//void display();
};

BinaryTree::BinaryTree()
{
	root=NULL;
}


void BinaryTree::insert()
{
	int data, choice;
	
	Node *newnode,*temp;
	newnode = new Node;

	if(isempty())
	{
		cout<<"Enter data for root:- ";
		cin>>data;
		newnode->data=data;
		newnode->left=NULL;
		newnode->right=NULL;
		root = newnode;
		temp = newnode;
	}
	else
}

int BinaryTree::isempty()
{
	if(root==NULL)
		return 1;
	return 0;
}


int main()
{
	int choice;
	BinaryTree b;

	while(1)
	{
		cout<<"\n\nBinary Tree Operations"<<endl;
		cout<<"1. Insert a node"<<endl;
		cout<<"2. Levelwise display"<<endl;
		cout<<"3. Find out depth of tree"<<endl;
		cout<<"4. Display leaf nodes"<<endl;
		cout<<"5. Create copy of tree"<<endl;
		cout<<"6. Exit program"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				b.insert();
				break;
			case 6:
				return 0;

			default:
				cout<<"\n\nError in choice,try again"<<endl;
		}
	}
	return 0;
}