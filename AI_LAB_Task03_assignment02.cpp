/*

Input:
8
MainGate Library 4
MainGate Cafeteria 2
Library AcademicBuildingA 5
Cafeteria AcademicBuildingA 8
Cafeteria CentralField 10
AcademicBuildingA IICT 6
CentralField IICT 3
Library CentralField 7
MainGate IICT

*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

map<string, vector<pair<string, ll>>> adj;

int main(){
    ll tt, i, j, k, n, m;

    cin >> n;
    for(i = 0; i < n; ++i){
        string s1, s2;
        cin >> s1 >> s2 >> m;
        adj[s1].pb({s2, m});
        adj[s2].pb({s1, m});
    }

    string strt, endd;
    cin >> strt >> endd;

    priority_queue<pair<ll, string>, vector<pair<ll, string>>, greater<pair<ll, string>>> pq;
    unordered_map<string, ll> dist;

    unordered_map<string, string> par;
    vector<string> exp;

    pq.push({0, strt});
    dist[strt] = 0;

    while(!pq.empty()){
        ll frntCost = pq.top().first;
        string frntNode = pq.top().second;

        pq.pop();

        if(frntCost > dist[frntNode])continue;

        exp.pb(frntNode);

        if(frntNode == endd) break;

        for(auto [nxt, wt] : adj[frntNode]){
            ll cos = frntCost + wt;
            if(!dist.count(nxt) || dist[nxt] > cos){
                dist[nxt] = cos;
                par[nxt] = frntNode;
                pq.push({cos, nxt});
            }
        }
    }
    if(!dist.count(endd)) cout << "NO PATH IS FOUND\n";
    else{

        vector<string> path;

        string cur = endd;

        while(cur != strt){
            path.pb(cur);
            cur = par[cur];
        }
        path.pb(strt);
        cout << "Optimal Path: ";
        for(i = path.size() - 1; i >= 0; --i){
            cout << path[i] << ' ';
        }cout << '\n';


        cout << "Total Cost: " << dist[endd] << '\n';

        cout << "Expanded Nodes: ";
        for(i = 0; i < exp.size(); ++i) cout << exp[i] << ' ';
        cout << '\n';
    }

}
