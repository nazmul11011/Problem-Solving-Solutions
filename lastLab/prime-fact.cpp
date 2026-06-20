#include <bits/stdc++.h>
using namespace std;

map <int,int> primeFactorize(int x) {
    map <int,int> factors;
    for (int i = 2; 1LL*i*i <= x; i++) {
        while (x % i == 0) {
            factors[i]++;
            x /= i;
        }
    }
    if (x > 1) factors[x]++; // remaining prime
    return factors;
}

int main() {
    int x = 84;
    auto factors = primeFactorize(x);
    for (auto &[p,c] : factors)
        cout << p << "^" << c << " ";
    cout << "\n";
}
