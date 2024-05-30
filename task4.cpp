#include <iostream>
#include <vector>

#define N 9

using namespace std;

bool isSafe(vector<vector<int> >& board, int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) {
            return false;
        }
        if (board[x][col] == num) {
            return false;
        }
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int> >& board, int row, int col) {
    if (row == N - 1 && col == N) {
        return true;
    }
    if (col == N) {
        row++;
        col = 0;
    }
    if (board[row][col] != 0) {
        return solveSudoku(board, row, col + 1);
    }
    for (int num = 1; num <= N; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudoku(board, row, col + 1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void printBoard(const vector<vector<int> >& board) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            cout << board[r][d] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int> > board(N, vector<int>(N, 0));

    if (solveSudoku(board, 0, 0)) {
        printBoard(board);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
