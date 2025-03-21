#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        // Sort the array to facilitate the two-pointer approach
        std::sort(nums.begin(), nums.end());

        // Iterate through the array with two pointers
        for (int i = 0; i < n - 3; ++i) {
            // Skip duplicate elements to avoid duplicate quadruplets
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                // Skip duplicate elements to avoid duplicate quadruplets
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        // Found a quadruplet
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates for the third number
                        while (left < right && nums[left] == nums[left + 1]) ++left;

                        // Skip duplicates for the fourth number
                        while (left < right && nums[right] == nums[right - 1]) --right;

                        // Move pointers inward
                        ++left;
                        --right;
                    } else if (sum < target) {
                        // If the sum is less than the target, move the left pointer to the right
                        ++left;
                    } else {
                        // If the sum is greater than the target, move the right pointer to the left
                        --right;
                    }
                }
            }
        }

        return result;
    }
};
