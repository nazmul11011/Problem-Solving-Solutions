#include <bits/stdc++.h>
#define MAXN 10005
#define MOD 998244353
#define lowbit(x) ((x) & (-x))
#define D 300
using namespace std;
#define ll long long

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t,a,b,d;
    cin >> t;
    while (t--) {
        cin >> a >> b;

        // ll d = a / b;
        ll max_gcd = 0;

        for (ll g = 1; g*g <= a; g++) {
            if (a % g == 0) {
                // max_gcd = g;
                // break;
                ll N=a/g;
                if(N>=b){
                    if(max_gcd>g) max_gcd=max_gcd;
                    else max_gcd=g;
                }
                if(g>=b){
                    if(max_gcd>N) max_gcd=max_gcd;
                    else max_gcd=N;
                }
            }
        }

        cout << max_gcd << endl;
    }

    return 0;
}