#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
const ll MOD = 1000000007;
ll modpow(ll a, ull e){
    ll res = 1 % MOD;
    a %= MOD;
    while(e){
        if(e & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int n; ull k;
        cin >> n >> k;
        vector<ull> pos;
        pos.reserve(n);
        for(int i=0;i<n;i++){
            ull s; cin >> s;
            pos.push_back(s - 1);
        }
        sort(pos.begin(), pos.end());
        int B = 0;
        while ((B < 63) && ((1ULL << B) <= k)) ++B;
        ull low = 0;
        for(ull p : pos){
            if(p < (ull)B) low |= (1ULL << p);
            else break;
        }
        auto fprime = [&](ull tval)->ull{
            if(tval <= (ull)B){
                ull m = 1ULL << tval;
                ull r = (tval>0 ? (low & (m - 1ULL)) : 0ULL);
                return (k + (m - 1ULL - r)) / m;
            } else {
                auto itL = lower_bound(pos.begin(), pos.end(), (ull)B);
                auto itR = lower_bound(pos.begin(), pos.end(), tval);
                if(itR > itL) return 0ULL;
                else return (low <= k - 1ULL) ? 1ULL : 0ULL;
            }
        };
        vector<ull> T;
        T.reserve((size_t)B + pos.size() + 5);
        for(int i=0;i<=B;i++) T.push_back((ull)i);
        for(ull p : pos) T.push_back(p);
        sort(T.begin(), T.end());
        T.erase(unique(T.begin(), T.end()), T.end());
        ll ans = 1;
        for(size_t i=0;i<T.size();++i){
            ull tval = T[i];
            ull a = fprime(tval);
            ull b = fprime(tval + 1ULL);
            ull cnt = 0;
            if(a >= b) cnt = a - b;
            if(cnt){
                ll base = (ll)((tval + 1ULL) % MOD);
                ans = (ans * modpow(base, cnt)) % MOD;
            }
        }
        cout << ans % MOD << '\n';
    }
    return 0;
}
