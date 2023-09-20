#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_valid(vector<vector<int>>& graph, vector<int>& colors, int v, int c) {
    for (int i = 0; i < graph[v].size(); i++) {
        int neighbor = graph[v][i];
        if (colors[neighbor] == c) {
            return false;
        }
    }
    return true;
}

bool graph_coloring(vector<vector<int>>& graph, vector<int>& colors, int v, int num_colors) {
    if (v == graph.size()) {
        return true; // All vertices are colored
    }
    for (int c = 1; c <= num_colors; c++) {
        if (is_valid(graph, colors, v, c)) {
            colors[v] = c;
            if (graph_coloring(graph, colors, v + 1, num_colors)) {
                return true;
            }
            colors[v] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    // Example graph
    vector<vector<int>> graph = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2}
    };
    int num_vertices = graph.size();
    int num_colors = 3; // Try to color the graph with 3 colors
    vector<int> colors(num_vertices, 0); // Initialize all colors to 0 (uncolored)
    if (graph_coloring(graph, colors, 0, num_colors)) {
        cout << "Solution: ";
        for (int i = 0; i < colors.size(); i++) {
            cout << colors[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No solution found." << endl;
    }
    return 0;
}

