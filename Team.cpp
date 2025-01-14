#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool possible = false;
        int index = -1;

        // Check if there exists an index `i` such that |a[i] - a[j]| % k != 0 for all j != i
        for (int i = 0; i < n; ++i) {
            bool valid = true;
            for (int j = 0; j < n; ++j) {
                if (i != j && abs(a[i] - a[j]) % k == 0) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                possible = true;
                index = i + 1; // Convert to 1-based index
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
            cout << index << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}