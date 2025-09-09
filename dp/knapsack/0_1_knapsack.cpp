#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll knapsack(ll n, ll w, const vector<ll>& weights, const vector<ll>& values) {
    vector<vector<ll>> solution(n + 1, vector<ll>(w + 1, 0));

    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= w; j++) {
            if (weights[i - 1] <= j){
                solution[i][j] = max(solution[i-1][j], values[i-1]+solution[i-1][j-weights[i-1]]);
            }
            else{
                solution[i][j] = solution[i - 1][j];
            }
        }
    }
    return solution[n][w];
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