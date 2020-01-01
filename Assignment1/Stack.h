class Node
{
	public:
		char data;
		Node *next;
};

class Stack
{
	Node *top;

	public:
		Stack();
		void push(char);
		char pop();
		char topelement();
		char isempty();
		void reverse();
		void display();

};
