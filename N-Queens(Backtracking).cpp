#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {

    // Check left side of row
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col, int n) {

    // Base case
    if (col >= n)
        return true;

    // Try placing queen in all rows of this column
    for (int i = 0; i < n; i++) {

        if (isSafe(board, i, col, n)) {

            board[i][col] = 1;   // Place queen

            if (solveNQueens(board, col + 1, n))
                return true;

            board[i][col] = 0;   // BACKTRACK
        }
    }

    return false;
}

int main() {

    int n;
    cout << "Enter value of N: ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueens(board, 0, n)) {

        cout << "\nSolution:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }

    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}