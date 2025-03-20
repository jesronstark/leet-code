#include <climits>

class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;

        // Variables to store the original number and the reversed number
        int original = x;
        long reversed = 0;

        // Reverse the digits of the number
        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        // Check if the reversed number is equal to the original
        return original == reversed;
    }
};
