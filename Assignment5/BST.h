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
		void insert();
		void deletenode();
		int search();
		void mirror(Node *);
		void display();
		void displaylevelwise();
		~BST();
};


