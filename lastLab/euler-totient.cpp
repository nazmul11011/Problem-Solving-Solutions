#include <bits/stdc++.h>
using namespace std;

int phi(int x) {
    int result = x;
    for (int i = 2; 1LL*i*i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) x /= i;
            result -= result / i;
        }
    }
    if (x > 1) result -= result / x;
    return result;
}

int main() {
    cout << phi(84) << "\n"; // Output: 24
}
