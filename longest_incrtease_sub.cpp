#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll LIS(vector<ll> &arr) {
    vector<ll> lis;
    
    for (ll x : arr) {
        
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
        } else {
            *it = x;
        }
    }
    return lis.size(); /* lis */
}

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++) cin >> arr[i];
    
    cout << LIS(arr) << endl;
    return 0;
}
