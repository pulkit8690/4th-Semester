#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check if there is a queen in the same row
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check if there is a queen in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check if there is a queen in the lower left diagonal
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // If there are no conflicts, it is safe to place a queen in this position
    return true;
}

bool solveNQueens(vector<vector<int>>& board, int col, int n) {
    // If all queens are placed, return true
    if (col == n) {
        return true;
    }

    // Try placing a queen in each row of the current column
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            // Place the queen in this position
            board[i][col] = 1;

            // Recursively place queens in the remaining columns
            if (solveNQueens(board, col + 1, n)) {
                return true;
            }

            // If placing the queen in this position doesn't lead to a solution,
            // remove the queen from this position and try the next row
            board[i][col] = 0;
        }
    }

    // If it is not possible to place a queen in any row of the current column,
    // return false
    return false;
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    // Initialize the board with all zeros
    vector<vector<int>> board(n, vector<int>(n, 0));

    // Solve the n-queens problem
    if (solveNQueens(board, 0, n)) {
        // Print the solution
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
