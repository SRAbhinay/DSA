#include <iostream>
#include <vector>
#include <stack>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v);
    void dfs(int startVertex);
    
private:
    int V;
    std::vector<std::vector<int>> adjList;
};

Graph::Graph(int vertices) : V(vertices) {
    adjList.resize(V);
}

void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
}

void Graph::dfs(int startVertex) {
    std::vector<bool> visited(V, false);
    std::stack<int> stack;
    
    visited[startVertex] = true;
    stack.push(startVertex);
    
    while (!stack.empty()) {
        int currentVertex = stack.top();
        stack.pop();
        
        std::cout << currentVertex << " ";
        
        for (const int& neighbor : adjList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                stack.push(neighbor);
            }
        }
    }
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    
    std::cout << "Depth-First Traversal starting from vertex 0: ";
    g.dfs(0);
    
    return 0;
}
