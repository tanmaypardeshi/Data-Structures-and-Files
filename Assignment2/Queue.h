#define SIZE 60
class Queue
{
	struct Node
	{
		char name[SIZE];
		int age;
		int priority;
		Node *next;
	};
	Node *front,*rear;
	
	public:
		Queue();
		void addq();
		void delq();
		void displayq();
		int isempty();
};
