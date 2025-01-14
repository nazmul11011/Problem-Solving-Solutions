#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool isTrue = false;
        ll index = -1;

        for (ll i = 0; i < n; ++i) {
            bool validated = true;
            for (ll j = 0; j < n; ++j) {
                if (i != j && abs(a[i] - a[j]) % k == 0) {
                    validated = false;
                    break;
                }
            }
            if (validated) {
                isTrue = true;
                index = i + 1;
                break;
            }
        }

        if(n==k){
            cout << "YES" << '\n' << n << '\n';
        }
            else if (isTrue) {
            cout << "YES" << '\n';
            cout << index << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}