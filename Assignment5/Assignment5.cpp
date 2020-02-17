#include<iostream>
#include "BST.cpp"
using namespace std;

class Operations
{
	BST b;
	
	public:
		void insert();
		void deletenode();
		void search();
		void mirror();
		void display();
		void displaylevelwise();
};

void Operations::insert()
{
	b.insert();
}

void Operations::deletenode()
{
	b.deletenode();
}

void Operations::search()
{
	B.search();
}

void Operations:mirror()
{
	b.mirror(b.getnode());
	b.display();
}

void Operations::display()
{
	b.display();
}

void Operations::displaylevelwise()
{
	b.displaylevelwise();
}


int main()
{
	int choice;
	Operaions o;
	
	while(1)
	{
		cout<<"\nBST Operations"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Delete node"<<endl;
		cout<<"3. Search node"<<endl;
		cout<<"4. Mirror tree"<<endl;
		cout<<"5. Display tree"<<endl;
		cout<<"6. Level wise display tree"<<endl;
		cout<<"7. Exit program"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				o.insert();
				break;
			case 2:
				o.deletenode();
				break;
			case 3:
				o.search();
				break;
			case 4:
				o.mirror();
				break;
			case 5:
				o.display();
				break;
			case 6:
				o.displaylevelwise();
				break;
			case 7:
				return 0;
			default:
				cout<<"\nError in choice, try again\n"<<endl;
		}
	}
}
