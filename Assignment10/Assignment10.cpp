#include <iostream>
#include <iomanip>
#define SIZE 100
using namespace std;

class Graph
{
    int vertices, edges;
    int graph[SIZE][SIZE];
    int distance[SIZE];
    int visited[SIZE];
    int mst[SIZE];

public:
    Graph() {}
    Graph(int, int);
    void create();
    void display();
    int findminvertex();
    void prims();
};

Graph::Graph(int v, int e)
{
    vertices = v;
    edges = e;

    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT32_MAX;
        visited[i] = 0;
        for (int j = 0; j < vertices; j++)
            graph[i][j] = 0;
    }
    distance[0] = 0;
}

void Graph::create()
{
    int source, destination, weight;
    for (int i = 0; i < edges; i++)
    {
        cout << "\nEnter the source vertex:- ";
        cin >> source;
        cout << "Enter the destination vertex:- ";
        cin >> destination;

        if (source != destination)
        {
            if (graph[source - 1][destination - 1] == 0 && graph[source - 1][destination - 1] == 0)
            {
                cout << "Enter the weight of the graph:- ";
                cin >> weight;
                graph[source - 1][destination - 1] = weight;
                graph[destination - 1][source - 1] = weight;
                cout << "Inserted edge between " << source << " and " << destination << endl;
            }
            else
            {
                cout << "\nEdge already exists. Please select a new edge" << endl;
                i--;
                continue;
            }
        }
        else
        {
            cout << "\nSource and destination cannot be the same\n";
            i--;
            continue;
        }
    }
    cout << "\n\nGraph created successfully" << endl;
}

void Graph::display()
{
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
            cout << setw(3) << graph[i][j];
        cout << endl;
    }
}

int Graph::findminvertex()
{
    int min = INT32_MAX;
    int min_index;

    for (int i = 0; i < vertices; i++)
        if (!visited[i] && distance[i] < min)
        {
            min = distance[i];
            min_index = i;
        }
    return min_index;
}

void Graph::prims()
{

    for (int i = 0; i < vertices; i++)
    {
        distance[i] = INT32_MAX;
        visited[i] = 0;
    }

    distance[0] = 0;
    mst[0] = -1;

    for (int i = 0; i < vertices - 1; i++)
    {
        int min = findminvertex();
        visited[i] = 1;

        for (int j = 0; j < vertices; j++)
        {
            if (!visited[j] && graph[i][j] && graph[i][j] < distance[j])
                mst[j] = min;
            distance[j] = graph[i][j];
        }
    }
    cout << "Edge\tWeight" << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << mst[i] << " - " << i << "\t" << graph[i][mst[i]];
    }
}

int main()
{
    Graph g;
    int choice, e, v;

    while (1)
    {

        cout << "\nImplementation of Kruskal's algorithm" << endl;
        cout << "1. Create graph" << endl;
        cout << "2. Display graph" << endl;
        cout << "3. Find shortest path using Dijkstra's algorithm" << endl;
        cout << "4. Exit the program" << endl;
        cout << "\nEnter your choice:- ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "\nEnter the number of vertices:- ";
            cin >> v;
            cout << "\nEnter the number of edges:- ";
            cin >> e;
            g = Graph(v, e);
            g.create();
            break;

        case 2:
            g.display();
            break;

        case 3:
            g.prims();
            break;

        case 4:
            return 0;

        default:
            cout << "\nError in choice, try again" << endl;
        }
    }
    return 0;
}