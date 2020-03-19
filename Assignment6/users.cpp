#include <iostream>
#include <stack>
#include <queue>
#include "users.h"
using namespace std;

int Graph::count = 1;

Graph::Graph()
{
    head = NULL;
}

int Graph::isempty()
{
    if (head == NULL)
        return 1;
    return 0;
}

void Graph::create_user(string name, int date, int month, int year, int comments)
{
    Vertex *temp;
    Vertex *current = new Vertex;

    current->id = Graph::count++;
    current->name = name;
    current->birthdate.dd = date;
    current->birthdate.mm = month;
    current->birthdate.yyyy = year;
    current->comments = comments;
    current->down = NULL;
    current->friends = NULL;

    if (head == NULL)
        head = current;

    else
    {
        temp = head;
        while (temp->down != NULL)
            temp = temp->down;
        temp->down = current;
    }
}

void Graph::display()
{
    Vertex *temp = head;

    while (temp != NULL)
    {
        cout << temp->id << ". " << temp->name << endl;
        temp = temp->down;
    }
}

void Graph::addfriend(string name1, string name2)
{
    Vertex *temp = head;
    Vertex *user1, *user2;
    Edge *newfriend1 = new Edge;
    Edge *newfriend2 = new Edge;
    Edge *temp1;

    while (temp != NULL && temp->name != name1)
        temp = temp->down;
    user1 = temp;

    while (temp != NULL && temp->name != name2)
        temp = temp->down;
    user2 = temp;

    if (user1 == NULL || user2 == NULL)
    {
        cout << "\nUser does not exist" << endl;
        return;
    }
    else
    {
        newfriend1->address = user2;
        newfriend1->next = NULL;
        newfriend2->address = user1;
        newfriend2->next = NULL;
    }

    if (user1->friends == NULL)
        user1->friends = newfriend1;
    else
    {
        temp1 = user1->friends;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = newfriend1;
    }

    if (user2->friends == NULL)
        user2->friends = newfriend2;
    else
    {
        temp1 = user2->friends;
        while (temp1->next != NULL)
            temp1 = temp1->next;
        temp1->next = newfriend1;
    }

    cout << endl;
    cout << user1->name << " is now a friend of " << user2->name << "." << endl;
}

void Graph::displayuser(string name)
{
    Vertex *temp = head;
    Edge *temp1;

    while (temp != NULL && temp->name != name)
        temp = temp->down;

    if (temp)
    {
        temp1 = temp->friends;
        cout << "\n-----" << temp->name << "'s Profile-----" << endl;
        cout << "\nBirthday : " << temp->birthdate.dd << "/" << temp->birthdate.mm << "/" << temp->birthdate.yyyy << endl;
        cout << "\nComments : " << temp->comments << endl;
        if (temp1)
        {
            int i = 1;
            cout << "\nFriends List:- " << endl;
            while (temp1 != NULL)
            {
                cout << i++ << ". " << temp1->address->name << endl;
                temp1 = temp1->next;
            }
        }
        cout << endl;
    }
    else
        cout << "\nUser does not exist." << endl;
}

void Graph::dfs(int month)
{
    stack<Vertex *> s;
    Edge *temp1;
    Vertex *temp = head;

    while (temp)
    {
        temp->visited = false;
        temp = temp->down;
    }

    temp = head;
    s.push(temp);
    head->visited = true;

    while (!s.empty())
    {
        temp = s.top();
        s.pop();

        if (temp->birthdate.mm == month)
            cout << temp->name << "\t" << temp->birthdate.dd << "/" << temp->birthdate.mm << "/" << temp->birthdate.yyyy << endl;
        temp1 = temp->friends;
        while (temp1)
        {
            if (!temp1->address->visited)
            {
                temp1->address->visited = 1;
                s.push(temp1->address);
            }
            temp1 = temp1->next;
        }
    }
}

void Graph::bfs()
{
    queue<Vertex *> q;
    int min, max;
    Edge *temp1;
    Vertex *temp = head;

    while (temp)
    {
        temp->visited = false;
        temp = temp->down;
    }

    min = head->comments;
    max = head->comments;

    temp = head;
    q.push(temp);
    head->visited = true;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->comments > max)
            max = temp->comments;
        if (temp->comments < max)
            max = temp->comments;

        temp1 = temp->friends;

        while (temp1)
        {
            if (!temp1->address->visited)
            {
                temp1->address->visited = true;
                q.push(temp1->address);
            }
            temp1 = temp1->next;
        }
    }

    cout << "\n-----MINIMUM COMMENTS-----" << endl;
    temp = head;
    while (temp != NULL)
    {
        if (temp->comments == min)
            cout << temp->name << "\t" << temp->comments << endl;
        temp = temp->down;
    }
    cout << "--------------------------" << endl;

    cout << "\n-----MAXIMUM COMMENTS-----" << endl;
    temp = head;
    while (temp != NULL)
    {
        if (temp->comments == max)
            cout << temp->name << "\t" << temp->comments << endl;
        temp = temp->down;
    }
    cout << "--------------------------" << endl;
}