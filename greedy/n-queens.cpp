#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

// function to check if queen can be placed at board[row][col]
bool isSafe(vector<string> &board, int row, int col, int n) {
    // check upper column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }

    // check upper left diagonal
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }

    // check upper right diagonal
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }

    return true;
}

// recursive function to solve N-Queens
void solve(vector<string> &board, int row, int n) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solve(board, row+1, n);
            board[row][col] = '.'; // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    solve(board, 0, n);
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> res = solveNQueens(n);

    for (auto &board : res) {
        for (auto &row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
