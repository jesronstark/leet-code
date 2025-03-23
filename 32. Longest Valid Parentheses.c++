#include <stack>
#include <string>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(const std::string& s) {
        std::stack<int> indices;
        indices.push(-1); // Base case to handle edge cases
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                indices.push(i);
            } else {
                indices.pop();
                if (indices.empty()) {
                    indices.push(i);
                } else {
                    maxLength = std::max(maxLength, i - indices.top());
                }
            }
        }

        return maxLength;
    }
};
