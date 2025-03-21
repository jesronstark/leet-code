#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 3) return result;

        // Sort the array to facilitate the two-pointer approach
        std::sort(nums.begin(), nums.end());

        // Iterate through the array
        for (int i = 0; i < n - 2; ++i) {
            // Skip duplicate elements to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Found a triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for the second number
                    while (left < right && nums[left] == nums[left + 1]) ++left;

                    // Skip duplicates for the third number
                    while (left < right && nums[right] == nums[right - 1]) --right;

                    // Move pointers inward
                    ++left;
                    --right;
                } else if (sum < 0) {
                    // If the sum is less than zero, move the left pointer to the right
                    ++left;
                } else {
                    // If the sum is greater than zero, move the right pointer to the left
                    --right;
                }
            }
        }

        return result;
    }
};
