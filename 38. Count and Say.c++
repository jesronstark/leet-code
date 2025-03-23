#include <string>

class Solution {
public:
    std::string countAndSay(int n) {
        if (n <= 0) return "";
        std::string result = "1";
        for (int i = 1; i < n; ++i) {
            result = getNextSequence(result);
        }
        return result;
    }

private:
    std::string getNextSequence(const std::string& sequence) {
        std::string nextSequence;
        int length = sequence.size();
        for (int i = 0; i < length; ++i) {
            int count = 1;
            while (i + 1 < length && sequence[i] == sequence[i + 1]) {
                ++i;
                ++count;
            }
            nextSequence += std::to_string(count) + sequence[i];
        }
        return nextSequence;
    }
};
