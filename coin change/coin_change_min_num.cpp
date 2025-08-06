#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int minCoins(const vector<int>& coins, int amount) {
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

    for(int i=0;i<=n;i++) dp[i][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<=amount;j++){
            if(coins[i-1]<=j){
                dp[i][j]=min(dp[i-1][j], 1+dp[i][j-coins[i-1]]);
            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][amount]>amount?-1:dp[n][amount];
}

int main() {
    int n, amount;
    cout << "Enter amount: ";
    cin >> amount;
    cout << "Enter number of coin types: ";
    cin >> n;
    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    int ans = minCoins(coins, amount);
    
    cout << "Minimum coins: " << ans << "\n";
    return 0;
}