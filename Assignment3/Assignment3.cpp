/* 
Assignment 3
Name:- Tanmay Pardeshi
Roll number:- 23260
Batch:- H10
*/

#include<iostream>
#include<math.h>
using namespace std;


struct Node
{
      Node *left,*right;
      int data;
};

class BinaryTree
{
        
	struct Node *root;
	
	public:
		BinaryTree();
		bool isempty();
		void create(int);
		void insert();
		Node *search();
		void preorder();
		void inorder();
		void postorder();
		void display();
		int depth();
		void leaf();
		void display_leaf();
		void copytree();
}

BinaryTree::BinaryTree()
{
	root=NULL;
	depthl=depthr=0;
	newroot=NULL;
}


bool isempty()
{
	if(root==NULL)
		return true;
	return false;
}

void create(int data)
{
	if(root==NULL)
	{
	root=new Node();
	root->left=NULL;
	root->right=NULL;
	root->data=data;
	}
}

void insert(int data,int key)
{
	char ch;
	if(root!=NULL)
	{
		Node *temp=search(root,key);
		if(temp!=NULL)
		{
			Node *n=new Node();
			n->data=data;
			n->left=NULL;
			n->right=NULL;

			cout<<"\nWhere u want to insert L/R:- ";
			cin>>ch;
			if(temp->left==NULL && (ch=='l' || ch=='L'))
				temp->left=n;
			else if(temp->right==NULL && (ch=='r' || ch=='R'))
				temp->right=n;
			else
				cout<<"Location Full";
		}
		else
			cout<<"key doesnt exist";
	}
}
Node *search(Node *root,T key)
{
	if(root!=NULL)
	{
		if(root->data==key)
			return root;
		else
		{
			Node *tempa=search(root->left,key);
			Node *tempb=search(root->right,key);
			if(tempa!=NULL)
				return tempa;
			else
				return tempb;
		}
	}
	else
		return NULL;
}


void preorder(Node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"\t";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"\t";
	}
}

void inorder(Node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<"\t";
		inorder(root->right);
	}
}

void display()
{
	int choice;
	while(1)
	{
		cout<<"\n1.Preorder"<<endl;
		cout<<"2.Inorder"<<endl;
		cout<<"3.Postorder"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"\nEnter display choice::";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nPreorder display:";
				preorder(root);
				break;

			case 2:
				cout<<"\nInorder display";
				inorder(root);
				break;

			case 3:
				cout<<"\nPostorder display";
				postorder(root);
				break;
		}

	}


int depth(Node *root)
{
	if(root==NULL)
	{
		return 0;	
	}
	return max(depth(root->left),depth(root->right))+1;
}

void leaf(Node *root)
{
	if(root!=NULL)
	{
		if((root->left==NULL)&&(root->right==NULL))
			cout<<root->data<<"\t";
		else
		{
			leaf(root->left);
			leaf(root->right);
		}
	}  
}

void display_leaf()
{
	cout<<"\nLeaf Nodes are:";
	leaf(root);
}

Node* copytree(Node *root,Node *newroot)
{
	if(root==NULL)
		return NULL;
	else
	{
		Node *tempa=new Node;
		Node *tempb=new Node;
		newroot=new Node;	
		newroot->data=root->data;
		newroot->left=copytree(root->left,tempa);
		newroot->right=copytree(root->right,tempb);
	}	
	return newroot;
}

int main()
{
	BinaryTree b;
	int a,key;
	int choice;
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
				cout<<"\nEnter element of tree:\n";
				cin>>a;
				b.create(a);
				cout<<"\nTree created successfully";
				break;
			case 2:
				if(!b.isempty())
				{
					cout<<"\nEnter the element to be inserted in tree:";
					cin>>a;
					cout<<"\nEnter key value to insert:";
					cin>>key;
					b.insert(a,key);
					cout<<"\nNew element inserted successfully";
				}                 
				else
					cout<<"\nFirst create tree";
				break;
			case 3:
				b.display();
				break;                              
			case 4:
				b.depth();
				break;
			case 5:
				b.display_leaf();
				break; 
			case 6:
				b.copytreecall(); 
				break;                 	
		}
	}
	return 0;
}

