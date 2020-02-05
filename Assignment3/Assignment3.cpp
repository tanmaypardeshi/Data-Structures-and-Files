/* 
Assignment 3
Name:- Tanmay Pardeshi
Roll number:- 23260
Batch:- H10
*/


#include<iostream>
#include<math.h>
#include<iomanip>
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
		int isempty();
		Node* getroot();
		Node* insert();
		void create();
		void display(Node *);
		int depth(Node *);
		void displayleaf(Node *);
		Node* copytree(Node *);
};


BinaryTree::BinaryTree()
{
	root=NULL;
}

int BinaryTree::isempty()
{
	if(root==NULL)
		return 1;
	return 0;
}

Node* BinaryTree::getroot()
{
	return root;
}


Node* BinaryTree::insert()
{
	Node *temp=new Node();
	char choice = 'y';
	
	cout<<"Enter data:- ";
	cin>>temp->data;
	
	cout<<"Do you want to add a left child of "<<temp->data<<" (y/n):- ";
	cin>>choice;
	if(choice == 'y' || choice=='Y')
		temp->left=insert();
	cout<<"Do you want to add a right child of "<<temp->data<<" (y/n):- ";
	cin>>choice;
	if(choice=='y' || choice=='Y')
		temp->right=insert();
	
	return temp;
}

void BinaryTree::create()
{
	root = insert();
}

void BinaryTree::display(Node *temp)
{
	if(temp != NULL)
	{
		display(temp->left);
		cout<<setw(3)<<temp->data;
		display(temp->right);
	}
	if(isempty())
		cout<<"\nTree is empty."<<endl;
}


int BinaryTree::depth(Node *temp)
{
	int depthLeft,depthRight;
	if(!isempty())
	{
		if(temp == NULL)
			return -1;
	
		return max(depthLeft,depthRight)+1;
	}
	else
		cout<<"Tree is empty"<<endl;
}

void BinaryTree::displayleaf(Node *temp)
{
	if(temp != NULL)
	{
		displayleaf(temp->left);
		if(temp->left == NULL && temp->right == NULL)
			cout<<setw(3)<<temp->data;
		displayleaf(temp->right);
	}
	if(isempty())
		cout<<"\nTree is empty."<<endl;
}

Node* BinaryTree::copytree(Node *root)
{
	Node *temp = NULL;
	if(root != NULL)
	{
		temp = new Node;
		temp->data = root->data;
		temp->left = copytree(root->left);
		temp->right = copytree(root->right);
	}
	return temp;	
}


int main()
{
	int choice;
	BinaryTree b;
	Node* node;

	while(1)
	{
		cout<<"\n\nBinary Tree Operations"<<endl;
		cout<<"1. Create tree"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Find out depth of tree"<<endl;
		cout<<"4. Display leaf nodes"<<endl;
		cout<<"5. Create copy of tree"<<endl;
		cout<<"6. Exit program"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				b.create();
				break;
			case 2:
				b.display(b.getroot());
				break;			
			case 3:
				cout<<"Depth of the given tree is :- "<<b.depth(b.getroot())<<endl;
				break;			
			case 4:
				b.displayleaf(b.getroot());
				break;
			case 5:
				node = b.copytree(b.getroot());
				cout<<"Tree has been copied successfully"<<endl;
				cout<<"Original tree is:- ";
				b.display(b.getroot());
				cout<<"\nCopied tree is:- ";
				b.display(node);
				break;
			case 6:
				return 0;

			default:
				cout<<"\n\nError in choice,try again"<<endl;
		}
	}
	return 0;
}
