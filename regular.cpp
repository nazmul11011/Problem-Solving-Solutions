#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back
const int NEG = -1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> parent(n+1, 0);
        for (int i = 2; i <= n; ++i) cin >> parent[i];
        vector<vector<int>> children(n+1);
        for (int i = 2; i <= n; ++i) children[parent[i]].pb(i);

        vector<int> depth(n+1, 0);
        queue<int> q;

        depth[1] = 1;
        q.push(1);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : children[u]) {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }

        int D = INT_MAX;
        for (int i = 1; i <= n; ++i) if (children[i].empty()) D = min(D, depth[i]);
        if (D == INT_MAX) D = 0;

        vector<int> cnt(D+1, 0);
        for (int i = 1; i <= n; ++i) if (depth[i] >= 1 && depth[i] <= D) cnt[depth[i]]++;
        int onesCap = n - k;
        
        vector<vector<int>> dp(k+1, vector<int>(onesCap+1, NEG));

        dp[0][0] = 0;

        for (int d = 1; d <= D; ++d) {
            int w = cnt[d];
            for (int a = k; a >= 0; --a) {
                for (int b = onesCap; b >= 0; --b) {
                    int cur = dp[a][b];
                    if (cur == NEG) continue;
                    if (a + w <= k) dp[a + w][b] = max(dp[a + w][b], cur + 1);
                    if (b + w <= onesCap) dp[a][b + w] = max(dp[a][b + w], cur + 1);
                }
            }
        }

        int ans = 0;

        for (int a = 0; a <= k; ++a) for (int b = 0; b <= onesCap; ++b) ans = max(ans, dp[a][b]);
        cout << ans << '\n';
    }
    return 0;
}
