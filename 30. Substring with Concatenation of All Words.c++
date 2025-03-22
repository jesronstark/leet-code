#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(const std::string& s, const std::vector<std::string>& words) {
        std::vector<int> result;
        if (words.empty() || s.empty()) return result;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int substringLength = wordLength * wordCount;

        if (s.size() < substringLength) return result;

        // Create a frequency map of the words
        std::unordered_map<std::string, int> wordMap;
        for (const auto& word : words) {
            wordMap[word]++;
        }

        // Slide over the string in windows of size substringLength
        for (int i = 0; i <= s.size() - substringLength; ++i) {
            std::unordered_map<std::string, int> seenWords;
            int j = 0;
            // Check each word in the current window
            for (; j < wordCount; ++j) {
                int wordStart = i + j * wordLength;
                std::string word = s.substr(wordStart, wordLength);
                // If the word is not in the original list, break
                if (wordMap.find(word) == wordMap.end()) {
                    break;
                }
                seenWords[word]++;
                // If the word is seen more times than it appears in the list, break
                if (seenWords[word] > wordMap[word]) {
                    break;
                }
            }
            // If all words match, add the starting index to the result
            if (j == wordCount) {
                result.push_back(i);
            }
        }

        return result;
    }
};
