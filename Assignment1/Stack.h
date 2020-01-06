/* 
Assignment 1
Name:- Tanmay Pardeshi
Roll number:- 23260
Batch:- H10
*/

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
