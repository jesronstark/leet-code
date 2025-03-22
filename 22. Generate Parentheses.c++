#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        generateCombinations(result, "", 0, 0, n);
        return result;
    }

private:
    void generateCombinations(std::vector<std::string>& result, std::string current, int open, int close, int max) {
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        if (open < max) {
            generateCombinations(result, current + "(", open + 1, close, max);
        }
        if (close < open) {
            generateCombinations(result, current + ")", open, close + 1, max);
        }
    }
};
