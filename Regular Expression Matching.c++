#include <vector>
#include <string>

class Solution {
public:
    bool isMatch(const std::string& s, const std::string& p) {
        int m = s.length();
        int n = p.length();
        // Create a 2D DP table with (m+1) x (n+1) dimensions
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
        // Base case: empty pattern matches empty string
        dp[0][0] = true;

        // Handle patterns like a*, a*b*, a*b*c* that can match an empty string
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // Current characters match, carry over the result
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // '*' can represent zero or more of the preceding element
                    dp[i][j] = dp[i][j - 2]; // Treat '*' as zero occurrence
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        // Treat '*' as one or more occurrences
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        // The result is in the bottom-right corner of the DP table
        return dp[m][n];
    }
};
