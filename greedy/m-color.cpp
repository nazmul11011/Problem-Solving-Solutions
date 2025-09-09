#include <bits/stdc++.h>
using namespace std;

int V; // Number of vertices

// Function to check if we can color vertex 'node' with color 'c'
bool isSafe(int node, int color[], vector<vector<int>> &graph, int c) {
    for (int i = 0; i < V; i++) {
        // If there is an edge and adjacent node has the same color
        if (graph[node][i] && color[i] == c) 
            return false;
    }
    return true;
}

// Recursive function to try coloring all vertices
bool solve(int node, vector<vector<int>> &graph, int m, int color[]) {
    if (node == V) return true; // All vertices colored successfully

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, color, graph, c)) {
            color[node] = c; // Assign color

            if (solve(node + 1, graph, m, color)) 
                return true;

            color[node] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    // Example: Graph with 4 vertices
    V = 4;
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors
    int color[V] = {0};

    if (solve(0, graph, m, color)) {
        cout << "Solution found:\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " ---> Color " << color[i] << "\n";
        }
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}
