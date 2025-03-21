#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(const std::string& s) {
        // Define mappings of Roman numerals to integer values
        std::unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int total = 0;
        int prevValue = 0;

        // Iterate over each character in the string
        for (char c : s) {
            int currentValue = romanMap[c];

            // If the previous value is less than the current value,
            // it indicates a subtractive combination
            if (prevValue < currentValue) {
                // Subtract twice the previous value to adjust the total
                // (once for the previous addition and once for subtraction)
                total += currentValue - 2 * prevValue;
            } else {
                total += currentValue;
            }

            prevValue = currentValue;
        }

        return total;
    }
};
