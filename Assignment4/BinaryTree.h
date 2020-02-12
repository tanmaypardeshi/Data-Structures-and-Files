struct Node
{
	char data;
	Node *left,*right;
};

class BinaryTree
{
	Node *root;

	public:
		BinaryTree();
		int isempty();
		int validate(char []);
		Node* getroot();
		Node* insert();
		void create();
		void inorder(Node *);
		void preorder(Node *);
		void postorder(Node *);
};

