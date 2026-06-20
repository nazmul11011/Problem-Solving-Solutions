#include <bits/stdc++.h>
using namespace std;

int countDivisors(int x) {
    int divs = 1;
    for (int i = 2; 1LL*i*i <= x; i++) {
        int cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        if (cnt) divs *= (cnt+1);
    }
    if (x > 1) divs *= 2;
    return divs;
}

int main() {
    int x = 84;
    cout << countDivisors(x) << "\n"; // Output: 12
}
