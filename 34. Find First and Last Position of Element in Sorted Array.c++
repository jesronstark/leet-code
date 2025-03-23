#include <vector>

class Solution {
public:
    std::vector<int> searchRange(const std::vector<int>& nums, int target) {
        int first = findFirstOccurrence(nums, target);
        int last = findLastOccurrence(nums, target);
        return {first, last};
    }

private:
    int findFirstOccurrence(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (left < nums.size() && nums[left] == target) {
            return left;
        }
        return -1;
    }

    int findLastOccurrence(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (right >= 0 && nums[right] == target) {
            return right;
        }
        return -1;
    }
};
