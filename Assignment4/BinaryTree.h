struct Node
{
	int data;
	Node *left,*right;
};

class BinaryTree
{
	Node *root;

	public:
		void BinaryTree();
		int isempty();
		void create(char []);
		void inorder(Node *);
		void preorder(Node *);
		void postorder(Node *);
		//void inorderrec(Node *);
		//void preorder(Node *);
		//void postorder(Node *);

};

