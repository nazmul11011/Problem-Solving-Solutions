#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

void UCS(vector<vector<pair<int,int>>> &adj, int start, int target) {
    int n = adj.size();

    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        auto[cost, u] = pq.top();
        pq.top();

        if(cost > dist[u]) continue;
        if(u == target){
            cout << "Min cost:" << cost << '\n';
            return;
        }
        for(auto [v, w] : adj[u]){
            if(dist[v] > cost + w){
                dist[v] = cost + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Target Not Reachable Using UCS\n";
}

int main() {
    int n,m;
    cout << "Number of nodes & edge: ";
    cin >> n >> m;

    vector<vector<pii>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        // adj[v].push_back({u, w}); // remove if graph is directed
    }

    int start = 0, target = 5;
    UCS(adj, 0, n-1);
}