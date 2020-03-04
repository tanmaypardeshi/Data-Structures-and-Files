#include <iostream>
#define MAX 100
using namespace std;


class Node1
{
	int id;
	Node2 *next;

	public:
		Node1(int);
	friend class Graph;
};

class Node2
{
    int id;
	char name[MAX];
    struct DOB
    {
    	int dd,mm,yyyy;
    }db;
    int comments;
    Node2 *down;
    Node1 *next;

	public:
    	Node2(int);
    friend class Graph;
};

class Graph
{
	Node2 *head;

	public:
		void create();
		int getindex(char []);
		void addfriends();
		void maxfriend();
		Node2 *getnode(char []);
		void show();

};
