#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXN = 1000;
int n, s, t;
int c[MAXN][MAXN], f[MAXN][MAXN], p[MAXN];

int augment() {
    memset(p, -1, sizeof(p)); // initialize parent array
    queue<int> q;
    q.push(s);
    p[s] = -2;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (p[v] == -1 && c[u][v] - f[u][v] > 0) { // if v is not visited and there is residual capacity
                p[v] = u;
                q.push(v);
            }
        }
    }
    if (p[t] == -1) return 0; // if there is no augmenting path, terminate
    int cf = INT_MAX;
    for (int v = t; v != s; v = p[v]) {
        int u = p[v];
        cf = min(cf, c[u][v] - f[u][v]); // find the minimum residual capacity
    }
    for (int v = t; v != s; v = p[v]) {
        int u = p[v];
        f[u][v] += cf; // update the flow
        f[v][u] -= cf; // update the reverse flow
    }
    return cf;
}

int maxflow() {
    int flow = 0;
    while (int cf = augment()) { // repeatedly find augmenting paths
        flow += cf; // add flow from the latest augmenting path
    }
    return flow;
}

int main() {
    cin >> n;
    cin >> s >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j]; // read the capacity matrix
        }
    }
    int max_flow = maxflow();
    cout << "Maximum flow: " << max_flow << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "f(" << i << "," << j << ") = " << f[i][j] << endl; // print the flow matrix
        }
    }
    return 0;
}
