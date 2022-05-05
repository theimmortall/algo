#include <iostream>
#include <list>
using namespace std;


class Graph 
{
private:
    int NVertices;
    list<int>* adjLists;
public:
    Graph(int vertices);
    void addEdge(int a, int b);
    void inputList();
    void BFS(int startVertex);
};

Graph::Graph(int vertices)
    : NVertices{vertices},
    adjLists{new list<int>[vertices]} 
	{
        cout << ".";
    }

void Graph::addEdge(int a, int b) {
    
    adjLists[a].push_back(b);
   
}

void Graph::inputList() {
    int numAdjVertices = 0;
    int adjVertex = 0;
    for (int i = 0; i < NVertices; i++) {
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

void Graph::BFS(int startVertex) {
    
    bool* visited = new bool[NVertices];
    for (int i = 0; i < NVertices; i++) {
        visited[i] = false;
    }

    list<int> queue;

    
    visited[startVertex] = true;
    queue.push_back(startVertex);

    
    list<int>::iterator i;

    while (!queue.empty()) {
       
        int currVertex = queue.front();
        cout << "Visited " << currVertex << "\n";
        queue.pop_front();

        
        for (i = adjLists[currVertex].begin();
        i != adjLists[currVertex].end(); i++) {
            int adjVertex = *i;
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                queue.push_back(adjVertex);
            }
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
    g.BFS(startingVertex);
    return 0;
}
