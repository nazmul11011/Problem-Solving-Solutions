#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    multiset<ll> s;  // Multiset to store elements
    vector<ll> result; // Vector to store output results
    ll t, operation, value;
    cin >> t;  // Number of operations

    while (t--) {
        cin >> operation;
        if (operation == 1) { 
            // Insert operation
            cin >> value;
            s.insert(value);
        } else if (operation == 2) { 
            // Erase operation
            cin >> value;
            s.erase(s.find(value));  // Remove one occurrence of 'value'
        } else if (operation == 3) { 
            // Retrieve the smallest element
            result.push_back(*s.begin());
        }
    }

    for (auto &u : result) 
        cout << u << '\n';  // Print the results

    return 0;
}
