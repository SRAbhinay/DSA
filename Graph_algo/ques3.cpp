#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;

int n, m;  // number of nodes and edges
vector<vector<int>> adj;  // adjacency list of the flow network
vector<vector<int>> cap;  // capacity matrix of the flow network
vector<vector<int>> flow;  // flow matrix of the flow network
vector<int> parent;  // parent vector for BFS
int max_flow = 0;  // maximum flow value
vector<bool> vis;  // visited vector for BFS

void add_edge(int u, int v, int w) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    cap[u][v] = w;
}

bool bfs(int s, int t) {
    vis.assign(n + 1, false);
    parent.assign(n + 1, -1);
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v] && cap[u][v] - flow[u][v] > 0) {
                vis[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return vis[t];
}

void augment_path(int s, int t) {
    int u = t;
    int b = INF;
    while (u != s) {
        int v = parent[u];
        b = min(b, cap[v][u] - flow[v][u]);
        u = v;
    }
    u = t;
    while (u != s) {
        int v = parent[u];
        flow[v][u] += b;
        flow[u][v] -= b;
        u = v;
    }
    max_flow += b;
}

void min_cut(int s, int t) {
    vector<bool> vis(n + 1);
    vis[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!vis[v] && cap[u][v] - flow[u][v] > 0) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        for (int v : adj[u]) {
            if (vis[u] && !vis[v] && cap[u][v] > 0) {
                cout << u << " " << v << "\n";
            }
        }
    }
}

void edmonds_karp(int s, int t) {
    while (bfs(s, t)) {
        augment_path(s, t);
    }
    min_cut(s, t);
}

int main() {
    n = 6;
    m = 9;
    adj.resize(n + 1);
    cap.resize(n + 1, vector<int>(n + 1));
    flow.resize(n + 1, vector<int>(n + 1));
    add_edge(1, 2, 6);
    add_edge(1, 3, 5);
    add_edge(2, 4, 4);
    add_edge(2, 5, 7);
    add_edge(3, 4, 2);
    add_edge(3, 5, 3);
    add_edge(4, 6, 5);
    add_edge(5, 6, 4);
    int s = 1;
    int t = 6;
    edmonds_karp(s, t);
    cout << "Maximum flow: " << max_flow << "\n";
    return 0;
}
