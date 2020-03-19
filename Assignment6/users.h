#include <iostream>
using namespace std;

struct DOB
{
    int dd, mm, yyyy;
};

struct Edge;

struct Vertex
{
    int id;
    string name;
    bool visited;
    DOB birthdate;
    int comments;
    Vertex *down;
    Edge *friends;
};

struct Edge
{
    Vertex *address;
    Edge *next;
};

class Graph
{
    Vertex *head;
    static int count;

public:
    Graph();
    int isempty();
    void create_user(string, int, int, int, int);
    void display();
    void addfriend(string, string);
    void displayuser(string);
    void dfs(int);
    void bfs();
};