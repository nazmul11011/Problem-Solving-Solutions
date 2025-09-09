#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n+1, INF);
    dp[0]=0;

    for(int i=1; i<=n;i++){
        int temp = i;
        while(temp>0){
            int digit=temp%10;
            temp /= 10;
            if(digit > 0) {
                dp[i] = min(dp[i], dp[i-digit] + 1);
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}