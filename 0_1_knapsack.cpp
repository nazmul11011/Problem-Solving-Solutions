#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int w, const vector<int>& weights, const vector<int>& values) {
    vector<vector<int>> solution(n + 1, vector<int>(w + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= w; j++) {
            if (weights[i - 1] <= j){
                solution[i][j] = max(solution[i-1][j], values[i-1]+solution[i-1][j-weights[i-1]]);
            }
            else{
                solution[i][j] = solution[i - 1][j];
            }
        }
    }
    return solution[n][w];
}

int main() {
    int n, w;
    cout << "Enter 2 numbers(items, weights): \n";
    cin >> n >> w;
    vector<int> weights(n), values(n);
    cout << "Enter weights: values: \n";
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> values[i];
    }
    int maxProfit = knapsack(n, w, weights, values);
    cout << "Maximum value in Knapsack: " << maxProfit << endl;
    return 0;
}