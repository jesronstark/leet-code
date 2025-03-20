#include <string>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1) return s; // Special case where zigzag pattern is unnecessary

        std::vector<std::string> rows(std::min(numRows, static_cast<int>(s.size())));
        int currentRow = 0;
        bool goingDown = false;

        // Iterate over each character in the input string
        for (char c : s) {
            rows[currentRow] += c;
            // Change direction when reaching the top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) goingDown = !goingDown;
            // Move to the next row
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all rows to form the final string
        std::string result;
        for (const std::string& row : rows) {
            result += row;
        }
        return result;
    }
};
