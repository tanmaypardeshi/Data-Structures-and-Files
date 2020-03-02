/* 
Assignment 2
Name:- Tanmay Pardeshi
Roll number:- 23260
Batch:- H10
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
	int data;
	Node *left,*right;
};

class Binarytree
{
	Node* root;


	public:
		Binarytree();
		Node* getNode()
		{
			return root; 
		}
		void create();
		Node* insert();
		void inorder(Node*);
		void inorderworec(Node*);
		int depth(Node*);
		void displayleaf(Node*);
		void copy();
		Node* tcopy(Node*);
};

Binarytree::Binarytree()
{
	root = NULL;
}

void Binarytree::create()
{
	root = insert();
}

Node* Binarytree::insert()
{
	Node *temp;
	char ch;

	temp = new Node();

	cout<<"\nEnter data to be added in the tree: ";
	cin>>temp->data;

	temp->left = temp->right = NULL;

	cout<<"\nWould you like to add a left child to "<<temp->data<<"?(y/n)";
	cin>>ch;
	if(ch == 'y' || ch == 'Y')
		temp->left = insert();

	cout<<"\nWould you like to add a right child to "<<temp->data<<"?(y/n)";
	cin>>ch;
	if(ch == 'y' || ch == 'Y')
		temp->right = insert();

	return temp;
}


void Binarytree::inorder(Node *t)
{
    if(t!=NULL)
    {
        inorder(t->left);
        cout<<t->data<<" ";
        inorder(t->right);
    }
}

void Binarytree::inorderworec(Node *t)
{
	stack<Node*> s;
	while(t!=NULL)
	{
		s.push(t);
		t = t->left;
	}
	while(!s.empty())
	{
		t = s.top();
		s.pop();
		cout<<t->data<<" ";
		t = t->right;
		while(t!=NULL)
		{
			s.push(t);
			t = t->left;
		}
	}
}

int Binarytree::depth(Node *t)
{
	int hl, hr;
	if(t == NULL)
		return 0;
	if(t->left == NULL && t->right == NULL)
		return 0;
	hl = depth(t->left);
	hr = depth(t->right);
	if(hl>hr)
		return (hl+1);
	return (hr+1);
}

void Binarytree::displayleaf(Node *t)
{
    if(!t)
        return;
    
    if(!t->left && !t->right)
    {
        cout<<t->data<<" ";
        return;
    }
    
    if(t->left)
        displayleaf(t->left);
    
    if(t->right)
        displayleaf(t->right);
}

void Binarytree::copy()
{
	Node*t;
	t = tcopy(root);
	inorder(t);
}

Node* Binarytree::tcopy(Node* t)
{
	Node* p;
	p = NULL;
	if(t != NULL)
	{
		p = new Node;
		p->data = t->data;
		p->left = tcopy(t->left);
		p->right = tcopy(t->right);
	}
	return p;
}


int main() 
{
	Binarytree t;
	int choice;
	while(1)
	{
        
		cout<<"\n\nOperations on binary tree: ";
		cout<<"\n1. Insert element in tree";
		cout<<"\n2. Display tree with recursion";
		cout<<"\n3. Display tree without recursion";
		cout<<"\n4. Depth of the tree";
		cout<<"\n5. Display leaf Nodes";
		cout<<"\n6. Create a copy of the tree";
		cout<<"\n7. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				t.create();
				break;
			
			case 2:
				cout<<"\nInorder traversal of the tree is: ";
				t.inorder(t.getNode());
				break;
			
			case 3: 
				cout<<"\nInorder traversal of the tree without recursion is: ";
				t.inorderworec(t.getNode());
				break;
			
			case 4: 
				cout<<"\nDepth of tree is: "<<t.depth(t.getNode());
				break;
			
			case 5: 
				cout<<"\nLeaf Nodes: ";
				t.displayleaf(t.getNode());
				break;
			
			case 6: 
				cout<<"\nCopy of the tree: ";
				t.copy();
				break;
			
			case 7: 
				return 0;
        }
    }
    return 0;
}
