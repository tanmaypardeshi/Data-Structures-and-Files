/* 
Assignment 2
Name:- Tanmay Pardeshi
Roll number:- 23260
Batch:- H10
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node
{
    char data;
    Node *left, *right;
};

class Expression
{
	char prefix[20], postfix[20], infix[20];
	Node* root;
	int top;
    
	public:
		void input(int);
		Node* getroot()
		{ 
			return root; 
		}
		int validate(int);
		Node* create_Post();
		void inorder_withRec(Node*);
		void preorder_withRec(Node*);
		void postorder_withRec(Node*);
		void inorder_withoutRec(Node*);
		void preorder_withoutRec(Node*);
		void postorder_withoutRec(Node*);
};


int Expression::validate(int x)
{
    int i = 0, opn = 0, opt = 0;
    if(x == 0)
    {
        for(;i<prefix[i]!='\0';i++)
        {
            if(prefix[i] == '+' || prefix[i] == '-' ||prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '%' || prefix[i] == '^' || prefix[i] == '$')
                opt++;
            else
                opn++;
        }
        
        if(opt != (opn-1))
            return 0;
        return 1;
    }
    else
    {
        for(;i<postfix[i]!='\0';i++)
        {
            if(postfix[i] == '+' || postfix[i] == '-' ||postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%' || postfix[i] == '^' || postfix[i] == '$')
                opt++;
            else
                opn++;
        }
        
        if(opt != (opn-1))
            return 0;
        return 1;
    }
}
void Expression::input(int x)
{
    if(x == 0)
    {
        while(1)
        {
            cout<<"\nEnter prefix Expression: ";
            cin>>prefix;
            if(validate(x))
                break;
            else
                cout<<"\nWrong Expression. Please enter again.";
        }
    }
    else
    {
        while(1)
        {
            cout<<"\nEnter postfix Expression: ";
            cin>>postfix;
            if(validate(x))
                break;
            else
                cout<<"\nWrong Expression. Please enter again.";
        }
    }
}

Node* Expression::create_Post()
{
    int i=0;
    Node* temp, *t1, *t2;
    stack<Node*> s;
    
    for(;postfix[i]!='\0';i++)
    {
        if(isalnum(postfix[i]))
        {
            temp = new Node;
            temp->data = postfix[i];
            temp->left = temp->right = NULL;
            s.push(temp);
        }
        else
        {
            t2 = s.top();
            s.pop();
            t1 = s.top();
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
           
void Expression::inorder_withRec(Node* t)
{
    if(t!=NULL)
    {
        inorder_withRec(t->left);
        cout<<" "<<t->data;
        inorder_withRec(t->right);
    }
}

void Expression::preorder_withRec(Node* t)
{
    if(t!=NULL)
    {
        cout<<" "<<t->data;
        preorder_withRec(t->left);
        preorder_withRec(t->right);
    }
}

void Expression::postorder_withRec(Node* t)
{
    if(t!=NULL)
    {
        postorder_withRec(t->left);
        postorder_withRec(t->right);
        cout<<" "<<t->data;
    }
}

void Expression::inorder_withoutRec(Node* t)
{
    Node* temp = t;
    stack<Node*> s;
    
    while(temp!=NULL)
    {
        s.push(temp);
        temp = temp->left;
    }
    
    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        cout<<" "<<temp->data;
        temp = temp->right;
        while(temp!=NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
}

void Expression::preorder_withoutRec(Node* t)
{
    Node* temp = t;
    stack<Node*> s;
    while(temp != NULL)
    {
        cout<<" "<<temp->data;
        s.push(temp);
        temp = temp->left;
    }
    
    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        temp = temp->right;
        while(temp != NULL)
        {
            cout<<" "<<temp->data;
            s.push(temp);
            temp = temp->left;
        }
    }
}

void Expression::postorder_withoutRec(Node* t)
{
    Node *t1, *temp = t;
    stack<Node*> s, s1;
    
    while(temp!=NULL)
    {
        s.push(temp);
        s1.push(NULL);
        temp = temp->left;
    }
        
    while(!s.empty())
    {
        temp = s.top();
        s.pop();
        t1 = s1.top();
        s1.pop();
        if(t1 == NULL)
        {
            s.push(temp);
            s1.push((Node*)1);
            temp = temp->right;
            while(temp!=NULL)
            {
                s.push(temp);
                s1.push(NULL);
                temp = temp->left;
            }
                
        }
        else
            cout<<" "<<temp->data;       
    }     
}
int main()
{
	int choice;
	Expression et;
	Node* t;

	cout<<"\nPlease enter the postfix string: ";
	et.input(1);
	t = et.create_Post();

	while(1)
	{
		cout<<"\n\nExpression Tree";
		cout<<"\nRecursive Traversals: ";
		cout<<"\n1. Inorder Traversal";
		cout<<"\n2. Preorder Traversal";
		cout<<"\n3. Postorder Traversal";
		cout<<"\nNon-Recursive Traversals: ";
		cout<<"\n4. Inorder Traversal";
		cout<<"\n5. Preorder Traversal";
		cout<<"\n6. Postorder Traversal";
		cout<<"\n7. Exit the program";
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		switch(choice)
		{
			case 1: 
				cout<<"\nInorder traversal with recursion:";
				et.inorder_withRec(t);
				break;
			case 2: 
				cout<<"\nPreorder traversal with recursion:";
				et.preorder_withRec(t);
				break;
			case 3: 
				cout<<"\nPostorder traversal with recursion:";
				et.postorder_withRec(t);
				break;
			case 4: 
				cout<<"\nInorder traversal without recursion:";
				et.inorder_withoutRec(t);
				break;
			case 5: 
				cout<<"\nPreorder traversal without recursion:";
				et.preorder_withoutRec(t);
				break;
			case 6: 
				cout<<"\nPostorder traversal without recursion:";
				et.postorder_withoutRec(t);
				break;
			case 7: 
				return 0;
			default: 
				cout<<"\nWrong choice. Please enter again.";
        }
    }
    return 0;
}
