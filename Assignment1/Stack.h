

template <class T>
class Stack
{
	
	struct Node
     {
	     T data;
	     Node *next;
     };
	Node *top;

	public:
		Stack();
		void push(T);
		T pop();
		T topelement();
		int isempty();
		void reverse();
		void display();

};
