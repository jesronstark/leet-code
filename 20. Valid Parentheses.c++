#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;

        // Traverse each character in the string
        for (char& ch : s) {
            // If it's an opening bracket, push it onto the stack
            if (ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            }
            // If it's a closing bracket
            else if (ch == ')' || ch == '}' || ch == ']') {
                // If the stack is empty or top doesn't match, it's invalid
                if (stack.empty() || !isMatchingPair(stack.top(), ch)) {
                    return false;
                }
                // Pop the matching opening bracket
                stack.pop();
            }
        }

        // If the stack is empty, all brackets were matched; otherwise, it's invalid
        return stack.empty();
    }

private:
    // Helper function to check if the pair of brackets matches
    bool isMatchingPair(char opening, char closing) {
        return (opening == '(' && closing == ')') ||
               (opening == '{' && closing == '}') ||
               (opening == '[' && closing == ']');
    }
};

