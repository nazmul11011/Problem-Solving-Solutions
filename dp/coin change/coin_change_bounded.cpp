#include <bits/stdc++.h>
using namespace std;

const int MOD = 100000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int n, K;
        cin >> n >> K;

        vector<int> A(n), C(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> C[i];

        vector<vector<int>> dp(n + 1, vector<int>(K + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= K; j++) {
                
                dp[i][j] = dp[i - 1][j];

                for (int k = 1; k <= C[i - 1]; k++) {
                    int val = j - k * A[i - 1];
                    if (val < 0) break;
                    dp[i][j] += dp[i - 1][val];
                    if (dp[i][j] >= MOD) dp[i][j] -= MOD;
                }
            }
        }

        cout << "Case " << tc << ": " << dp[n][K] % MOD << "\n";
    }

    return 0;
}
