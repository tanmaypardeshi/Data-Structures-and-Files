/* 
Assignment 2
Name:- Tanmay Pardeshi
Roll number:- 23260
Batch:- H10
*/

template <class T>
struct node
{
	T data;
	node* next;
};

template <class T>
class Queue 
{
	node<T> *front,*rear;
	public:
		Queue();
		void addq(T);
		void delq();
		int isqempty();
		void displayq();
}; 
