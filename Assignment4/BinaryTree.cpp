#include<iostream>
#include<stack>
#include<queue>
#include "BinaryTree.h"
using namespace std;


BinaryTree::BinaryTree()
{
	root = NULL;
}

int BinaryTree::isempty()
{
	if(root == NULL)
		return 1;
	return 0;
}

/*int BinaryTree::validate(char postfix[])
{
	int i=0, operand=0, operatr=0;
	while(postfix[i]!='\0')
	{
		if(postfix[i] == '+' || postfix[i] == '-' ||postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%' || postfix[i] == '^' || postfix[i] == '$')
			operatr++;
		else
			operand++;
	}

	if(operatr != (operand-1))
		return 0;
	return 1;
}
*/

Node* BinaryTree::getroot()
{
	return root;
}

void BinaryTree::create()
{	
	root = insert();
}	

Node* BinaryTree::insert()
{
	Node *temp,*t1,*t2;
	stack<Node *> s;
	char postfix[50];
	int i=0;

	cout<<"Enter a postfix expression:- ";
	cin>>postfix;
	cout<<"Testing2";

	while(postfix[i]!='\0')
	{
		if(isalnum(postfix[i]))
		{
			temp = new Node;
			temp->data = postfix[i];
			temp->left = NULL;
			temp->right = NULL;
			s.push(temp);
		}
		else
		{
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			temp = new Node;
			temp->data = postfix[i];
			temp->left = t1;
			temp->right = t2;
			s.push(temp);
		}
	}
	temp = s.top();
	s.pop();
	return temp;
}

void BinaryTree::preorder(Node *root)
{
	try
	{
		if(root==NULL)
			throw "Tree is empty";
		cout<<root->data<<"\t";
		preorder(root->left);
		preorder(root->right);
	}
	catch(char *msg)
	{
		cout<<msg<<endl;
	}
}

void BinaryTree::inorder(Node *root)
{
	try
	{
		if(root==NULL)
			throw "Tree is empty";
		
		inorder(root->left);
		cout<<root->data<<"\t";
		inorder(root->right);
	}
	catch(char *msg)
	{
		cout<<msg<<endl;
	}
}

void BinaryTree::postorder(Node *root)
{
	try
	{
		if(root==NULL)
			throw "Tree is empty";
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"\t";

	}
	catch(char *msg)
	{
		cout<<msg<<endl;
	}
}
