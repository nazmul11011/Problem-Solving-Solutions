#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

void aStar(int start, int goal, vector<vector<pii>>& graph, vector<int>& heuristic) {
    int n = graph.size();

    vector<int> g(n, INT_MAX);     
    vector<int> parent(n, -1);    

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    g[start] = 0;
    pq.push({heuristic[start], start});

    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();

        if (current == goal)
            break;

        for (auto edge : graph[current]) {
            int next = edge.first;
            int cost = edge.second;

            if (g[current] + cost < g[next]) {
                g[next] = g[current] + cost;
                int f = g[next] + heuristic[next];
                pq.push({f, next});
                parent[next] = current;
            }
        }
    }

    if (g[goal] == INT_MAX) {
        cout << "No path found\n";
        return;
    }

    vector<int> path;
    for (int v = goal; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Shortest Path: ";
    for (int node : path)
        cout << node << " ";

    cout << "\nTotal Cost: " << g[goal] << endl;
}

int main() {
    int n, m;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<pii>> graph(n);

    cout << "Enter edges (u v cost):\n";
    for (int i = 0; i < m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
    }

    vector<int> heuristic(n);
    cout << "Enter heuristic values for each node:\n";
    for (int i = 0; i < n; i++)
        cin >> heuristic[i];

    int start, goal;
    cout << "Enter start node: ";
    cin >> start;

    cout << "Enter goal node: ";
    cin >> goal;

    aStar(start, goal, graph, heuristic);

    return 0;
}

/*
nodes: 6
edges: 7
(u v cost):
0 1 1
0 2 3
1 3 4
2 3 1
2 4 6
3 5 2
4 5 1
heuristic: 7, 6, 4, 2, 1, 0
start node: 0
goal node: 5
*/