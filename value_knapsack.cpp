#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1e18;

ll knapsack(ll n, ll W, const vector<ll>& weights, const vector<ll>& values) {
    ll maxValueSum = 0;
    for (ll v : values) maxValueSum += v;

    vector<ll> dp(maxValueSum + 1, INF);
    dp[0] = 0;

    for (ll i = 0; i < n; i++) {
        for (ll v = maxValueSum; v >= values[i]; v--) {
            dp[v] = min(dp[v], dp[v - values[i]] + weights[i]);
        }
    }

    ll ans = 0;
    for (ll v = 0; v <= maxValueSum; v++) {
        if (dp[v] <= W) ans = v;
    }
    return ans;
}

int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll> weights(n), values(n);
    for (ll i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    cout << knapsack(n, w, weights, values) << endl;
    return 0;
}
