#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<long long> cnt(n + 1, 0);
        for (int x : a) if (x <= n) cnt[x]++;

        long long ans = 0;
        for (int x = 1; x <= n; ++x) {
            if (cnt[x] >= x) {
                ans += (cnt[x] / x) * x;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}