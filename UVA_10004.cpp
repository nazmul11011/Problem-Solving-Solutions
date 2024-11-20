#include <bits/stdc++.h>
#define ll long long int
#define endl '\n'
using namespace std;

int adj[500][500];  // Adjacency matrix
int color[500];     // Color array

bool bicolor(int n, int s) {
    queue<int> q;
    q.push(s);
    color[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(adj[u][u]==1) return false;

        for(int i=0; i<n;i++){
            if(adj[u][i] && color[i]==-1){
                q.push(i);
                color[i]= 1-color[u];
            }else if (adj[u][i] && color[u]==color[i]){
                return false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        ll n, e, a, b;
        cin >> n;
        if (n == 0) break; // Terminate on input n == 0
        cin >> e;

        memset(adj, 0, sizeof(adj));     // Clear adjacency matrix
        memset(color, -1, sizeof(color)); // Reset color array

        for (int i = 0; i < e; i++) {
            cin >> a >> b;
            adj[a][b] = 1;
            adj[b][a] = 1;
        }

        if (bicolor(n, 0)) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}
