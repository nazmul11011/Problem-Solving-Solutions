#include <bits/stdc++.h>
using namespace std;

void solve(string start, string target) {
    queue<pair<string, int>> q;
    unordered_set<string> vis;

    q.push({start, 0});
    vis.insert(start);

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [state, steps] = q.front();
        q.pop();

        if (state == target) {
            cout << "Minimum moves = " << steps << '\n';
            return;
        }

        int pos = state.find('0');   // position of empty cell
        int x = pos / 3;
        int y = pos % 3;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
                string nextState = state;
                swap(nextState[x * 3 + y], nextState[nx * 3 + ny]);

                if (!vis.count(nextState)) {
                    vis.insert(nextState);
                    q.push({nextState, steps + 1});
                }
            }
        }
    }

    cout << "No solution exists\n";
}

int main() {
    string start, target;

    cin >> start;   // Example: 123405678
    cin >> target;  // Example: 123456780

    solve(start, target);

    return 0;
}