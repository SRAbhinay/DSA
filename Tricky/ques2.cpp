#include <iostream>
#include <vector>

using namespace std;

const int N = 9; // Size of the Sudoku grid

// Function to print the Sudoku grid
void printGrid(vector<vector<int>> grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the given digit can be placed at the given position
bool canPlace(vector<vector<int>>& grid, int row, int col, int digit) {
    // Check if digit is already present in the row or column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == digit || grid[i][col] == digit) {
            return false;
        }
    }
    // Check if digit is already present in the 3x3 subgrid
    int subgridRow = row - row % 3;
    int subgridCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[subgridRow+i][subgridCol+j] == digit) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku problem using backtracking
bool solveSudoku(vector<vector<int>>& grid, int row, int col) {
    // Check if we have reached the end of the grid
    if (row == N) {
        return true; // Solution found
    }
    // Check if we have reached the end of the current row
    if (col == N) {
        return solveSudoku(grid, row+1, 0); // Move to next row
    }
    // Check if the current cell is already filled
    if (grid[row][col] != 0) {
        return solveSudoku(grid, row, col+1); // Move to next column
    }
    // Try to place each digit (from 1 to 9) at the current position
    for (int digit = 1; digit <= 9; digit++) {
        if (canPlace(grid, row, col, digit)) {
            grid[row][col] = digit; // Place the digit at the current position
            if (solveSudoku(grid, row, col+1)) {
                return true; // Solution found
            }
            grid[row][col] = 0; // Remove the digit from the current position and try the next one
        }
    }
    return false; // No solution found
}

int main() {
    vector<vector<int>> grid(N, vector<int>(N));
    cout << "Enter the Sudoku grid (use 0 for empty cells):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    if (solveSudoku(grid, 0, 0)) {
        cout << "Solution:\n";
        printGrid(grid);
    } else {
        cout << "No solution found.\n";
    }
    return 0;
}

