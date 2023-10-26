#include <iostream>
#include <vector>

using namespace std;

const int N = 9;
vector<vector<int>> board(N, vector<int>(N, 0));
int solutionCount = 0;

bool isValid(int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }

    int startRow = row - (row % 3);
    int startCol = col - (col % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(int row, int col) {
    if (row == N - 1 && col == N) {
        solutionCount++;
        return;
    }

    if (col == N) {
        row++;
        col = 0;
    }

    if (board[row][col] != 0) {
        solveSudoku(row, col + 1);
        return;
    }

    for (int num = 1; num <= N; num++) {
        if (isValid(row, col, num)) {
            board[row][col] = num;
            solveSudoku(row, col + 1);
            board[row][col] = 0; 
        }
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    solveSudoku(0, 0);

    cout <<solutionCount << endl;

    return 0;
}

