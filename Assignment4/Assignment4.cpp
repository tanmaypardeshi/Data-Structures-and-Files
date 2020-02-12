#include <iostream>
#include "BinaryTree.cpp"
using namespace std;


class Expression
{
	BinaryTree b;
	
	public:
		void input();
		int validate(char []);
		void preordertraversal();
		void inordertraversal();
		void postordertraversal();
};


void Expression::input()
{
	b.create();
	cout<<"Created Tree Successfully";
}
	
void Expression::preordertraversal()
{
	int choice;
	
	while(1)
	{
		cout<<"\n\nPreorder Traversal"<<endl;
		cout<<"1. Recursive method"<<endl;
		cout<<"2. Non Recursive method"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				b.preorder(b.getroot());
				break;
			case 2:
			case 3:
				return;
				
		}
	}
}

void Expression::inordertraversal()
{
	int choice;
	
	while(1)
	{
		cout<<"\n\nInorder Traversal"<<endl;
		cout<<"1. Recursive method"<<endl;
		cout<<"2. Non Recursive method"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				b.inorder(b.getroot());
				break;
			case 2:
			case 3:
				return;
				
		}
	}
}

void Expression::postordertraversal()
{
	int choice;
	
	while(1)
	{
		cout<<"\n\nPostorder Traversal"<<endl;
		cout<<"1. Recursive method"<<endl;
		cout<<"2. Non Recursive method"<<endl;
		cout<<"3. Exit"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				b.postorder(b.getroot());
				break;
			case 2:
			case 3:
				return;
				
		}
	}
}

int main()
{
	int choice;
	Expression e;
	
	
	while(1)
	{
		cout<<"\nExpression Tree"<<endl;
		cout<<"1. Create tree from postfix expression"<<endl;
		cout<<"2. Preorder traversal"<<endl;
		cout<<"3. Inorder traversal"<<endl;
		cout<<"4. Postorder traversal"<<endl;
		cout<<"5. Exit program"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				e.input();
				break;
			case 2:
				e.preordertraversal();
				break;
			case 3:
				e.inordertraversal();
				break;
			case 4:
				e.postordertraversal();
				break;
			case 5:
				return 0;
			default:
				cout<<"Error in choice, try again"<<endl;
		}
	}
	return 0;
}
