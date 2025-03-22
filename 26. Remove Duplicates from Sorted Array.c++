#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) return 0;

        int uniqueIndex = 0; // Index to place the next unique element

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[uniqueIndex]) {
                ++uniqueIndex;
                nums[uniqueIndex] = nums[i];
            }
        }

        return uniqueIndex + 1; // Length of array with unique elements
    }
};
