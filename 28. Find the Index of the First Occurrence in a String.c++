#include <cstring> // For std::strstr
#include <string>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        // If needle is empty, return 0 as per problem statement
        if (needle.empty()) {
            return 0;
        }

        // Use std::strstr to find the first occurrence of needle in haystack
        const char* result = std::strstr(haystack.c_str(), needle.c_str());

        // If needle is not found, return -1
        if (result == nullptr) {
            return -1;
        }

        // Calculate and return the index of the first occurrence
        return result - haystack.c_str();
    }
};
