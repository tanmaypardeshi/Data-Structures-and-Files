class LinkedList
{
	struct Node
	{
		int data;
		int flag;
		Node *next;
	};
   	Node *head;
    	
    	LinkedList();
    	void insert(int,int);
    	int deletenode(int);
    	void display();
};

