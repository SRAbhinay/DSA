#include <iostream>
#include <queue>     
 
#include <vector>     
 

using namespace std;

const int INF = 1e9;

// Define the flow network as a graph
vector<vector<int>> graph;
vector<vector<int>> capacity;
vector<vector<int>> flow;
vector<int> parent;

// Perform BFS to find the shortest augmenting path
bool bfs(int source, int sink) {
    parent.assign(graph.size(), -1);
    parent[source] = -2;
    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
            if (parent[v] == -1 && capacity[u][v] > flow[u][v]) {
                parent[v] = u;
                if (v == sink)
                    return true;
                q.push(v);
            }
        }
    }
    return false;
}

// Compute the maximum flow in the flow network
int edmondsKarp(int source, int sink) {
    int maxFlow = 0;
    flow.assign(graph.size(), vector<int>(graph.size(), 0));

    while (bfs(source, sink)) {
        int pathFlow = INF;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            pathFlow = min(pathFlow, capacity[u][v] - flow[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            flow[u][v] += pathFlow;
            flow[v][u] -= pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main() {
    // Construct the flow network as a graph
    int n, m;
    cin >> n >> m;

    graph.assign(n, vector<int>());
    capacity.assign(n, vector<int>(n, 0));
    flow.assign(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back(v);
        graph[v].push_back(u);
        capacity[u][v] += c;
    }

    int source, sink;
    cin >> source >> sink;

    // Compute the maximum flow using the Edmonds-Karp algorithm
    int maxFlow = edmondsKarp(source, sink);
    cout << "Maximum flow: " << maxFlow << endl;

    return 0;
}

