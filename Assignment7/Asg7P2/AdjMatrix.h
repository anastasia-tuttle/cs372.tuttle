//
//  AdjacencyMatrix.h
//  Asg6P3
//
//  Created by Anastasia Tuttle  on 10/19/22.
//
// Adjacency Matrix representation in C++
#include <iostream>
using namespace std;
class Graph {
private:
    bool** adjMatrix;
    int numVertices;
public:
    // Initialize the matrix to zero
    Graph(int numVertices)
    {
        this->numVertices = numVertices;
        adjMatrix = new bool*[numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = false;
        }
    }
    // Add edges
    void addEdge(int i, int j) {
        adjMatrix[i][j] = true;
        adjMatrix[j][i] = true;
    }
    // Remove edges
    void removeEdge(int i, int j) {
        adjMatrix[i][j] = false;
        adjMatrix[j][i] = false;
    }
    // Print the martix
    void toString() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << " : ";
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }
    ~Graph() {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};
bool adjacent(ValueType x, ValueType y)
{
    return (x == y);
}
//Return a vector of neighbor nodes
vector<ValueType> neighbors(ValueType x)
{
    while (x != Nullptr)
    {
        cout<<" -> " <<ptr->val;
        prt = prt->next;
    }
    cout<<endl;
}
//add an edge from source, to dest
//I add dest if it isn't already in graph
void addEdge (ValueType source, ValueType dest)
{
    //chcek if nodes are there or not
    if (adj.find(u) == adj.end() && adj.find(v) == adj.end())
    {
        cout << "both nodes not found\n";
    }
    else if (adj.find(u) == adj.end())
    {
        cout << "source node not found\n";
    }
    else if (adj.find(v) == adj.end())
    {
        cout << "destination node not found\n";
    }
    else
    {
        if (adj[u].find(v) == adj[u].end())
        {
            adj[u].insert(v);
            adj[v].insert(u);
            cout << "Edge added to the graph\n";
        }
        else
        {
            cout << "Edge already exists\n";
        }
    }
}
//Add x to graph
void addNode (ValueType x)
{
    //check if node alreday there
    if (adj.find(u) != adj.end())
    {
        cout << "Node already present\n";
    }
    else
    {
        unordered_set<int> st; //empty list
        adj[u] = st;
        cout << "node added to the graph\n";
    }
}
void deleteEdge (ValueType source, ValueType dest)
{
    //chcek if nodes are there or not
    if (adj.find(u) == adj.end() && adj.find(v) == adj.end())
    {
        cout << "both nodes not found\n";
    }
    else if (adj.find(u) == adj.end())
    {
        cout << "source node not found\n";
    }
    else if (adj.find(v) == adj.end())
    {
        cout << "destination node not found\n";
    }
    else
    {
        if (adj[u].find(v) == adj[u].end())
        {
            cout << "Edge doesn't exist\n";
        }
        else
        {
            adj[u].erase(v);
            adj[v].erase(u);
            cout << "Edge deleted from the graph\n";
        }
    }
}
void deleteNode (ValueType node)
{
    //check if node is there or not
    if (adj.find(u) == adj.end())
    {
        cout << "Node not present\n";
    }
    else
    {
        //delete list of the node to be deleted
        adj.erase(u);
        //delete from others node's list
        for (auto it = adj.begin(); it != adj.end(); it++)
        {
            if (it->second.find(u) != it->second.end())
            {
                it->second.erase(u);
            }
        }
        cout << "node deleted from the graph\n";
    }
}
void dfs(N startNode)
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
     
    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            dfs(*i);
}
void bfs(N startNode)
{
// Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V,false);
     
    // Create a queue for BFS
    list<int> queue;
     
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
     
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();
     
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent: adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}


