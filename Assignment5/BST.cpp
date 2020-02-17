#include<iostream>
#include "BST.h"
using namespace std;

BST::BST()
{
	root=NULL;
	root->left=NULL;
	root->right=NULL;
}

Node* BST::getroot()
{
	return root;
}

void BST::insert()
{
	Node *temp,*newnode;
	char ask='y';
	
	while(ask=='y' || ask=='Y')
	{
		if(root==NULL)
			cout<<"Enter data for root:- ";
		else
			cout<<"Enter data for newnode:- ";
		newnode = new Node;
		cin>>newnode->data;
		newnode->left = newnode->right=NULL;
		
		if(root==NULL)
			root=newnode;
		else
		{
			temp=root;
			while(1)
			{
				if(newnode->data < temp->data)
				{
					if(temp->left==NULL)
					{
						temp->left=newnode;
						break;
					}
					else
						temp=temp->left;
				}
				else	//newnode->data > temp->data
				{
					if(temp->right==NULL)
					{
						temp->right=newnode;
						break;
					}
					else
						temp=temp->right;
				}
			}
		}
		cout<<"Do you want to add more node(y/n):- ";
		cin>>ask;
	}
}

void deletenode()
{
	int data;
	Node *temp,*parent_temp,*rn,*parent_rn,*son;
	
	cout<<"Enter the value of the node to be deleted:- ";
	cin>>data;
	
	parent_temp=NULL;
	temp=root;
	
	while(temp!=NULL)
	{
		if(data==temp->data)
			break;
		parent_temp=temp;
		if(data<temp->data)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(temp==NULL)
	{
		cout<<"Node with data "<<data<<" not found"<<endl;
		return;
	}
	if(temp->left==NULL)
		rn=temp->right;
	else
	{
		if(temp->right==NULL)
			rn=temp->right;
		else
		{
			parent_rn = temp;
			rn = parent_rn->right;
			son = rn->left;
			
			while(son!=NULL)
			{
				parent_rn=rn;
				rn=son;
				son=son->left;
			}
			if(parent_rn!=temp)
			{
				parent_rn->left=rn->right;
				rn->right=temp->right;
			}
			rn->left=temp->left;
		}
		//if node to be deleted is root node
		if(parent_temp==NULL)
			root=rn;
		else
		{
			//node to delete is parent's left child
			if(temp==parent_temp->left)
				parent_temp->left=rn;
			else
				parent_temp->right=rn;
		}
	}
	delete temp;
	cout<<"Node with data:- "<<data<<" has been deleted"<<endl;
}


void BST::search()
{
	int data;
	Node *temp;
	
	cout<<"Enter data to be searched:- ";
	cin>>data;
	
	temp=root;
	
	while(temp!=NULL)
	{
		if(data==temp->data)
			break;
		if(data<temp->data)
			temp=temp->left;
		else
			temp=temp->right;
	}
	if(temp==NULL)
		cout<<"Data:- "<<data<<" not found in the BST"<<endl;
	else
		cout<<"Data:- "<<data<<" found in the BST"<<endl;
}


void BST::mirror(Node *r)
{
	Node* temp;
	
	if(root!=NULL)
	{
		temp=r->left;
		r->left=r->right;
		r->right=temp;
		
		mirror(r->left);
		mirror(r->right);
	}
	else
		return;
}
	

void BST::display()
{
	if(root==NULL)
		return;
	else
	{
		display(root->left);
		cout<<" "<<root->data<<" ";
		dispaly(root->right);
	}
}
	
