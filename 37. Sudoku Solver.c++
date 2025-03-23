#include <vector>

class Solution {
public:
    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }

private:
    bool solve(std::vector<std::vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num;
                            if (solve(board)) {
                                return true;
                            }
                            board[row][col] = '.'; // Backtrack
                        }
                    }
                    return false; // Trigger backtracking
                }
            }
        }
        return true; // Puzzle solved
    }

    bool isValid(const std::vector<std::vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; ++i) {
            // Check row
            if (board[row][i] == num) {
                return false;
            }
            // Check column
            if (board[i][col] == num) {
                return false;
            }
            // Check 3x3 sub-grid
            int subRow = 3 * (row / 3) + i / 3;
            int subCol = 3 * (col / 3) + i % 3;
            if (board[subRow][subCol] == num) {
                return false;
            }
        }
        return true;
    }
};
