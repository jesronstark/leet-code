 #include <string>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        // Define mappings of integer values to Roman numeral symbols
        std::vector<std::pair<int, std::string>> valueSymbols = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        std::string result;

        // Iterate over the mappings
        for (const auto& [value, symbol] : valueSymbols) {
            // Append the symbol while num is greater than or equal to the value
            while (num >= value) {
                result += symbol;
                num -= value;
            }
        }

        return result;
    }
};
