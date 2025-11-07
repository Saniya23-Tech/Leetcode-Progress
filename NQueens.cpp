#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n) {
    int i, j;

    // Horizontal
    for (j = 0; j < n; j++) {
        if (board[row][j] == 'Q')
            return false;
    }

    // Vertical
    for (i = 0; i < n; i++) {
        if (board[i][col] == 'Q')
            return false;
    }

    // Left upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
            return false;
    }

    // Right upper diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(board, row, j, n)) {
            board[row][j] = 'Q';
            nQueens(board, row + 1, n, ans);
            board[row][j] = '.'; // backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    nQueens(board, 0, n, ans);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<string>> result = solveNQueens(n);

    for (auto &board : result) {
        for (auto &row : board)
            cout << row << endl;
        cout << endl;
    }

    return 0;
}
