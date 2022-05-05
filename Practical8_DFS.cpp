#include <iostream>
#include <list>
using namespace std;


class Graph {
private:
    int numVertices;
    list<int>* adjLists;
    bool* visited;
public:
    Graph(int vertices);
    void addEdge(int a, int b);
    void inputList();
    void DFS(int vertex);
};

Graph::Graph(int vertices)
    : numVertices{vertices},
    adjLists{new list<int>[vertices]},
    visited{new bool[vertices]} {
        cout << "Graph constructor called\n";
}

void Graph::addEdge(int a, int b) {
    
    adjLists[a].push_back(b);
    
}

void Graph::inputList() {
    int numAdjVertices = 0;
    int adjVertex = 0;
    for (int i = 0; i < numVertices; i++) {
        cout << "Enter number of vertices connected to ";
        cout << i << ": ";
        cin >> numAdjVertices;
        for (int j = 0; j < numAdjVertices; j++) {
            cout << "Enter adjecent vertex: ";
            cin >> adjVertex;
            addEdge(i, adjVertex);
        }
    }
}

void Graph::DFS(int vertex) {
    visited[vertex] = true;
    cout << "Visited " << vertex << "\n";
    list<int> adjlist = adjLists[vertex];
    list<int>::iterator i;
    for (i = adjlist.begin();
    i != adjlist.end(); i++) {
        if (!visited[*i]) {
            DFS(*i);
        }
    }

}

int main() {
   

    int v = 0;
    cout << "Enter number of vertices in the graph: ";
    cin >> v;

    Graph g(v);

    g.inputList();

    int startingVertex = 0;
    cout << "Enter vertex to start from: ";
    cin >> startingVertex;

    cout << "BFS (starting from vertex "
        << startingVertex << ")\n";
    g.DFS(startingVertex);
    return 0;
}