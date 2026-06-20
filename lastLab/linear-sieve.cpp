#include <bits/stdc++.h>
using namespace std;

vector<int> linearSieve(int n) {
    vector<int> lp(n+1, 0), primes;
    for (int i = 2; i <= n; i++) {
        if (lp[i] == 0) {  // i is prime
            lp[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > lp[i] || 1LL * i * p > n) break;
            lp[i * p] = p;
        }
    }
    return primes;
}

int main() {
    int n = 50;
    vector<int> primes = linearSieve(n);
    for (int p : primes) cout << p << " ";
    cout << "\n";
}
