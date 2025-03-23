#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(const std::vector<std::vector<char>>& board) {
        // Arrays to track seen numbers in rows, columns, and sub-boxes
        std::vector<std::unordered_set<char>> rows(9);
        std::vector<std::unordered_set<char>> cols(9);
        std::vector<std::unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num == '.') {
                    continue; // Skip empty cells
                }
                // Calculate box index
                int boxIndex = (i / 3) * 3 + (j / 3);
                // Check for duplicates in row, column, and box
                if (rows[i].count(num) || cols[j].count(num) || boxes[boxIndex].count(num)) {
                    return false;
                }
                // Add number to the respective sets
                rows[i].insert(num);
                cols[j].insert(num);
                boxes[boxIndex].insert(num);
            }
        }
        return true;
    }
};
