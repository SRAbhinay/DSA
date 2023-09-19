#include <iostream>
#include <vector>
#include <queue>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v);
    int shortestPath(int src, int target);
    
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

int Graph::shortestPath(int src, int target) {
    std::vector<bool> visited(V, false);
    std::vector<int> dist(V, -1);
    std::queue<int> queue;
    
    visited[src] = true;
    dist[src] = 0;
    queue.push(src);
    
    while (!queue.empty()) {
        int currentVertex = queue.front();
        queue.pop();
        
        for (const int& neighbor : adjList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[currentVertex] + 1;
                queue.push(neighbor);
            }
        }
    }
    
    return dist[target];
}

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    
    int src = 0, target = 5;
    int shortestDist = g.shortestPath(src, target);
    
    if (shortestDist != -1)
        std::cout << "Shortest Path from " << src << " to " << target << " is " << shortestDist << " units." << std::endl;
    else
        std::cout << "There is no path from " << src << " to " << target << "." << std::endl;
    
    return 0;
}
