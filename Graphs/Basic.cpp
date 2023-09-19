#include <iostream>
#include <vector>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v);
    void printGraph();
    
private:
    int V;
    std::vector<std::vector<int>> adjList;
};

Graph::Graph(int vertices) : V(vertices) {
    adjList.resize(V);
}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::printGraph() {
    for (int i = 0; i < V; ++i) {
        std::cout << "Adjacency list of vertex " << i << ": ";
        for (const int& neighbor : adjList[i])
            std::cout << neighbor << " ";
        std::cout << std::endl;
    }
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    
    g.printGraph();
    
    return 0;
}
