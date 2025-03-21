#include <vector>
#include <algorithm>
#include <cstdlib> // For std::abs

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        // Sort the array to facilitate the two-pointer approach
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2]; // Initialize with the first three elements

        // Iterate through the array
        for (int i = 0; i < n - 2; ++i) {
            // Use two pointers to find the closest sum
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // Update the closest sum if the current one is closer to the target
                if (std::abs(currentSum - target) < std::abs(closestSum - target)) {
                    closestSum = currentSum;
                }

                // Move the pointers based on the comparison between currentSum and target
                if (currentSum < target) {
                    ++left;
                } else if (currentSum > target) {
                    --right;
                } else {
                    // If currentSum equals target, it's the closest possible sum
                    return currentSum;
                }
            }
        }

        return closestSum;
    }
};
