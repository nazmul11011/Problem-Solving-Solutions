#include <bits/stdc++.h>
using namespace std;

// int coinChangeWays(const vector<int>& coins, int amount) {
//     int n = coins.size();
//     vector<vector<int>> solution(n + 1, vector<int>(amount + 1, 0));

//     for (int i = 0; i <= n; i++) {
//         for (int j = 0; j <= amount; j++) {
//             if (i == 0 && j == 0) {
//                 solution[i][j] = 1;
//             } else if (i == 0) {
//                 solution[i][j] = 0;
//             } else if (j == 0) {
//                 solution[i][j] = 1;
//             } else {
//                 if (coins[i - 1] > j) {
//                     solution[i][j] = solution[i - 1][j];
//                 } else {
//                     solution[i][j] = solution[i - 1][j] + solution[i][j - coins[i - 1]];
//                 }
//             }
//         }
//     }
//     return solution[n][amount];
// }

int coinChangeWays(vector<int>& coins, int amount){
    vector<unsigned int> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins){
        for (int j = coin; j <= amount; j++){
            dp[j] += dp[j - coin];
        }
    }
    return dp[amount];
}

int main() {
    int amount, n;
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