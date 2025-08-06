#include <bits/stdc++.h>
using namespace std;

// int coinChangeWays(const vector<int>& coins, int amount) {
//     int n = coins.size();
//     vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

//     for (int j = 0; j <= n; j++){
//         dp[0][j] = 1;
//     }

//     for (int i = 0; i <= amount; i++){
//         for (int j = 0; j <= n; j++){
//             int coin = coins[j - 1];

//             dp[i][j] = dp[i][j - 1];

//             if (i >= coin){
//                 dp[i][j] += dp[i - coin][n];
//             }
//         }
//     }
//     return dp[amount][n];
// }

int coinChangeWays(vector<int>& coins, int target){
    vector<unsigned int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; i++){
        for (int num : coins){
            if (i >= num){
                dp[i] += dp[i - num];
            }
        }
    }

    return dp[target];
}

int main() {
    int amount;
    int n;
    cout << "Enter amount: ";
    cin >> amount;
    cout << "Enter number of coin types: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int ways = coinChangeWays(coins, amount);
    cout << "Number of ways to make change: " << ways << endl;
    return 0;
}