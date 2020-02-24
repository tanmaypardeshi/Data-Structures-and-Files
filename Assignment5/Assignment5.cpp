#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

struct Node
{
	int data;
	Node *left,*right;
};

class BST
{
	Node *root;
	
	public:
		BST();
		Node* getroot();
		Node* getmirror();
		void insert();
		Node* deletenode(Node*,int);
		void search();
		void mirror(Node *);
		void display(Node *);
		void displaylevelwise();
		int getheight(Node *);
};


BST::BST()
{
	root=NULL;
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

Node* BST::deletenode(Node* t,int data)
{
	Node *temp;

	if(t == NULL)
	{
		cout<<"\nElement not found!";
		return t;
	}
	else if(data < t->data)
	{
		t->left = deletenode(t->left, data);
		return t;
	}
	else if(data > t->data)
	{
		t->right = deletenode(t->right, data);
		return t;
	}
	else
	{
	   
		if(t->left == NULL && t->right == NULL)
		{
			temp = t;
			delete temp;
			return NULL;
		}

		if(t->left == NULL)
		{
			temp = t;
			t = t->right;
			delete temp;
			return t;
		}
		if(t->right == NULL)
		{
			temp = t;
			t = t->left;
			delete temp;
			return t;
		}
		
		temp = t->right;
		
		while(temp->left != NULL)
			temp = temp->left;
		
		t->data = temp->data;
		t->right = deletenode(t->right, temp->data);
		return t;
	}
	return NULL;
	
}


void BST::search()
{
	int data;
	Node *temp;
	
	if(root==NULL)
	{
		cout<<"\nCreate a tree first"<<endl;
		return;
	}
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
		cout<<data<<" not found in the BST"<<endl;
	else
		cout<<data<<" found in the BST"<<endl;
}


void BST::mirror(Node *r)
{
	Node* temp;
	
	if(r!=NULL)
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
		
void BST::display(Node *root)
{
	if(root == NULL)
		return;
	else
	{
		display(root->left);
		cout<<" "<<root->data<<" ";
		display(root->right);
	}

}

void BST::displaylevelwise()
{
	queue<Node *> q;
	Node *current;
	Node *temp=root;
	
	if(temp==NULL)
	{
		cout<<"\nCreate a tree first"<<endl;
		return;
	}
	q.push(temp);
	q.push(NULL);
	
	
	while(q.size()>1)
	{
		current = q.front();
		q.pop();
		
		if(current==NULL)
		{
			q.push(NULL);
			cout<<endl;
		}	
		else
		{
			if(current->left)
				q.push(current->left);
			if(current->right)
				q.push(current->right);
			
			cout<<current->data<<"  ";
		}
	}
}

int BST::getheight(Node* t)
{
	int left=0,right=0;
	if(t==NULL)
		return -1;
	else
	{
		left=getheight(t->left);
		right=getheight(t->right);
	}
	return max(left,right)+1;
}
	
		


int main()
{
	int choice;
	BST b;	
	while(1)
	{
		cout<<"\nBST Operations"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete node"<<endl;
		cout<<"3. Search node"<<endl;
		cout<<"4. Mirror tree"<<endl;
		cout<<"5. Display tree"<<endl;
		cout<<"6. Level wise display tree"<<endl;
		cout<<"7. Height of tree"<<endl;
		cout<<"8. Exit program"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				b.insert();
				break;
			
			case 2:
				cout<<"Enter data to delete:- ";
				int data;
				cin>>data;
				else
					cout<<"Element "<<data<<" deleted"<<endl;					
				break;
			
			case 3:
				b.search();
				break;
			
			case 4:
				if(b.getroot()==NULL)
				{
					cout<<"\nCreate a tree first"<<endl;
					break;
				}
				b.mirror(b.getroot());
				cout<<"\nMirror image of tree is:- ";
				b.display(b.getroot());
				cout<<endl;
				b.mirror(b.getroot());
				break;
			
			case 5:
				cout<<"\nTree is:- ";
				b.display(b.getroot());
				break;
			
			case 6:
				cout<<"\nLevel order display of tree is:- \n";
				b.displaylevelwise();
				break;
			
			case 7:
				cout<<"Height of the given tree is "<<b.getheight(b.getroot())<<endl;
				break;
			
			case 8:
				return 0;
			
			default:
				cout<<"\nError in choice, try again\n"<<endl;
		}
	}
	return 0;
}
