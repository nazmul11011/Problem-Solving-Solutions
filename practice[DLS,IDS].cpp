#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool dls(int start, int target, int depth, int limit, vector<vector<ll>> &adj,  vector<ll> &vis) {
    if (start == target) return true;
    if (depth == limit) return false;
    
    vis[start] = 1;
    for (auto it : adj[start]) {
        if(!vis[it]){
            if(dls(it, target, depth + 1, limit, adj, vis)) return true;
        }
    }
    return false;
}

void DLS_Main(vector<vector<ll>> &adj, vector<ll> &vis) {
    int start = 0, target = 5, limit = 2;
    if(dls(start, target, 0, limit, adj, vis)){
        cout << "Target Found Using DLS\n";
    } else {
        cout << "Target Not Found By this limit using DLS\n";
    }
}

void IDS_Main(vector<vector<ll>> &adj, vector<ll> &vis) {
    int start = 0, target = 5, maxDepth = 5;
    bool flag = 0;

    for(int limit = 0; limit <= maxDepth; limit++){
        fill(vis.begin(), vis.end(), 0);

        if(dls(start, target, 0, limit, adj, vis)) {
            cout << "Found at depth " << limit << '\n';
            flag = 1;
            break;
        }
    }
    if(!flag) cout << "Target Not Found\n";
}

int main() {
    int n,i;
    cout << "Number of nodes: ";
    cin >> n;

    vector<vector<ll>> adj(n+1);
    vector<ll> vis(n+1, 0);

    for(i = 0; i < n-1; ++i) {
        ll first, second;
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }

    DLS_Main(adj, vis);
    IDS_Main(adj, vis);
}