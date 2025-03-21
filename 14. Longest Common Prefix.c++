#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";

        // Sort the array of strings
        std::sort(strs.begin(), strs.end());

        // Compare the first and last strings in the sorted array
        const std::string& first = strs.front();
        const std::string& last = strs.back();
        int minLength = std::min(first.size(), last.size());

        int i = 0;
        while (i < minLength && first[i] == last[i]) {
            ++i;
        }

        return first.substr(0, i);
    }
};

