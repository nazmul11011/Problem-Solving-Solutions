#include <bits/stdc++.h>
#define MAXN 10005
#define MOD 998244353
#define lowbit(x) ((x) & (-x))
#define D 300
using namespace std;
#define ll long long

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t, n, b, B;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> arr(n), temp(n, 1);
        map<ll, ll>mp;
        for (auto &u : arr) {
            cin >> u;
            mp[u]++;
        }

        if (n < 4) {cout << "-1" << '\n';continue;}
        ll f=0,g=0;
        for(auto u:mp){
            if(u.second>1){
                if(!f) f=u.first;
                else { g = u.first; break; }
            }
        }
        if(!f || !g) {cout << "-1" << '\n';continue;}
        ll st1=0,st2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==f && !st1) {temp[i]=2;st1=1;}
            else if(arr[i]==g && !st2) {temp[i]=3;st2=1;}

            if(st1 && st2) break;
        }        
        for(auto u:temp) cout << u << ' ';cout << '\n';
    }

    return 0;
}