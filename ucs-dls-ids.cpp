#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define dbg(x) cout << #x << " = " << x << '\n'

using namespace std;

bool dls(ll start, ll target, ll depth, ll limit, vector<vector<ll>> &adj, vector<ll> &vis){
    if(start == target){
        return 1;
    }
    if(depth == limit){
        return 0;
    }
    vis[start] = 1;
    for(auto it : adj[start]){
        if(!vis[it]){
            if(dls(it, target, depth + 1, limit, adj, vis)) return 1;
        }
    }
    return 0;
}

void DLS_Main(vector<vector<ll>> &adj, vector<ll> &vis){
    ll start = 0, target = 5; // ASSUMING
    ll limit = 2;

    if(dls(start, target, 0, limit, adj, vis)){
        cout << "Target Found Using DLS\n";
    }
    else{
        cout << "Target Not Found By this limit\n";
    }
}

void IDS_Main(vector<vector<ll>> &adj, vector<ll> &vis){
    ll start = 0, target = 5, maxDepth = 5;
    bool flag = 0;
    for(ll limit = 0; limit <= maxDepth; ++limit){
        fill(vis.begin(), vis.end(), 0);

        if (dls(start, target, 0, limit, adj, vis)) {
            cout << "Found at depth " << limit << '\n';
            flag = 1;
            break;
        }
    }
    if(!flag){
        cout << "Target Not Found\n";
    }
}

void UCS(vector<vector<pair<ll, ll>>> &adj){
    ll n = adj.size(), start = 0, tar = n - 1;
    vector<ll> dist(n + 1, INT_MAX);

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0, start});
    dist[start] = 0;

    while(!pq.empty()){
        auto [cost, u] = pq.top();
        pq.pop();

        if(u == tar){
            cout << "Target Found at UCS\nMin Cost = " << cost << '\n';
            return;
        }
        if(cost > dist[u]) continue;

        for(auto [v, w] : adj[u]){
            if(dist[v] > cost + w){
                dist[v] = cost + w;
                pq.push({dist[v], v});
            }
        }
    }
    cout << "Target Not Reachable Using UCS\n";
}


int main(){
    ll n, i;
    cin >> n;
    vector<vector<ll>> adj(n + 1);
    vector<ll> vis(n + 1, 0);

    for(i = 0; i < n - 1; ++i){
        ll first, second;
        cin >> first >> second;
        adj[first].pb(second);
        adj[second].pb(first);
    }
    DLS_Main(adj, vis);

    IDS_Main(adj, vis);

    //FOR UCS
    n = 4;
    vector<vector<pair<ll,ll>>> adj1(n);

    adj1[0].push_back({1, 1});
    adj1[0].push_back({2, 4});

    adj1[1].push_back({0, 1});
    adj1[1].push_back({3, 2});

    adj1[2].push_back({0, 4});
    adj1[2].push_back({3, 1});

    adj1[3].push_back({1, 2});
    adj1[3].push_back({2, 1});


    UCS(adj1);

}
