#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return {};

        // Mapping of digits to corresponding letters
        const std::vector<std::string> digitToLetters = {
            "",    // 0
            "",    // 1
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs",// 7
            "tuv", // 8
            "wxyz" // 9
        };

        std::vector<std::string> combinations;
        std::string currentCombination;

        // Start backtracking from the first digit
        backtrack(digits, 0, digitToLetters, currentCombination, combinations);
        return combinations;
    }

private:
    void backtrack(const std::string& digits, int index,
                   const std::vector<std::string>& digitToLetters,
                   std::string& currentCombination,
                   std::vector<std::string>& combinations) {
        // If the current combination is complete
        if (index == digits.size()) {
            combinations.push_back(currentCombination);
            return;
        }

        // Get the letters corresponding to the current digit
        int digit = digits[index] - '0';
        const std::string& letters = digitToLetters[digit];

        // Iterate over each letter and proceed recursively
        for (char letter : letters) {
            currentCombination.push_back(letter);
            backtrack(digits, index + 1, digitToLetters, currentCombination, combinations);
            currentCombination.pop_back(); // Backtrack
        }
    }
};
