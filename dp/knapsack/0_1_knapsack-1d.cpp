#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll knapsack(ll n, ll w, const vector<ll>& weights, const vector<ll>& values) {
    vector<ll> dp(w + 1, 0);

    for (ll i = 0; i < n; i++) {
        for (ll j = w; j >= weights[i]; j--) {
            dp[j] = max(dp[j], values[i] + dp[j - weights[i]]);
        }
    }
    
    return dp[w];
}

int main() {
    ll n, w;
    // cout << "Enter 2 numbers(items, weights): \n";
    cin >> n >> w;
    vector<ll> weights(n), values(n);
    // cout << "Enter weights: values: \n";
    for (ll i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    ll maxProfit = knapsack(n, w, weights, values);
    // cout << "Maximum value in Knapsack: " << maxProfit << endl;
    cout << maxProfit << endl;
    return 0;
}