#include <iostream>
#include <queue>
using namespace std;

const int MAX_SIZE = 100;

int adj[MAX_SIZE][MAX_SIZE]; // adjacency matrix
bool visited[MAX_SIZE];
int parent[MAX_SIZE];

void bfs(int u, int v) {
    queue<int> Q;
    Q.push(u);
    visited[u] = true;
    parent[u] = -1;
    
    while (!Q.empty()) {
        int curr = Q.front();
        Q.pop();
        
        for (int i = 0; i < MAX_SIZE; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                parent[i] = curr;
                Q.push(i);
                
                if (i == v) {
                    // path from u to v has been found
                    cout << "Path from " << u << " to " << v << ": ";
                    int node = v;
                    while (node != -1) {
                        cout << node << " ";
                        node = parent[node];
                    }
                    cout << endl;
                    return;
                }
            }
        }
    }
    
    cout << "No path found from " << u << " to " << v << endl;
}

int main() {
    // Sample adjacency matrix
    adj[1][2] = adj[2][1] = 1;
    adj[1][3] = adj[3][1] = 1;
    adj[1][4] = adj[4][1] = 1;
    adj[2][5] = adj[5][2] = 1;
    adj[2][6] = adj[6][2] = 1;
    adj[3][6] = adj[6][3] = 1;
    adj[3][7] = adj[7][3] = 1;
    adj[4][7] = adj[7][4] = 1;
    adj[5][7] = adj[7][5] = 1;
    adj[6][7] = adj[7][6] = 1;
    
    // Find path from vertex 1 to 7
    bfs(1, 7);
    
    return 0;
}
