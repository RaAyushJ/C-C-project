#include <iostream>
using namespace std;

const int N = 9;

int board[N][N] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

void printBoard() {
    cout << "-------------------------\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j == 0) cout << "| ";
            if (board[i][j] == 0)
                cout << ". ";
            else
                cout << board[i][j] << " ";
            if ((j + 1) % 3 == 0) cout << "| ";
        }
        cout << "\n";
        if ((i + 1) % 3 == 0)
            cout << "-------------------------\n";
    }
}

bool isValid(int row, int col, int num) {
    // Check row
    for (int x = 0; x < N; x++)
        if (board[row][x] == num)
            return false;

    // Check column
    for (int x = 0; x < N; x++)
        if (board[x][col] == num)
            return false;

    // Check 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[startRow + i][startCol + j] == num)
                return false;

    return true;
}

bool isFull() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (board[i][j] == 0)
                return false;
    return true;
}

int main() {
    cout << "Welcome to Sudoku!\n";
    while (!isFull()) {
        printBoard();
        int row, col, num;
        cout << "Enter row (1-9), column (1-9), and number (1-9): ";
        cin >> row >> col >> num;
        row--; col--; // 0-based indexing

        if (row < 0 || row >= N || col < 0 || col >= N || num < 1 || num > 9) {
            cout << "Invalid input! Try again.\n";
            continue;
        }

        if (board[row][col] != 0) {
            cout << "Cell already filled! Try again.\n";
            continue;
        }

        if (isValid(row, col, num)) {
            board[row][col] = num;
        } else {
            cout << "Invalid move! That number can't go there.\n";
        }
    }

    cout << "\n🎉 Congratulations! You completed the Sudoku!\n";
    printBoard();
    return 0;
}
