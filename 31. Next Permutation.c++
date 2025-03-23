#include <algorithm>
#include <vector>

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the end
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        if (i >= 0) {
            // Step 2: Find the element just larger than nums[i] to swap with
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                --j;
            }
            std::swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the elements from i + 1 to the end
        std::reverse(nums.begin() + i + 1, nums.end());
    }
};
