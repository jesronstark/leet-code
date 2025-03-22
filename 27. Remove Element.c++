#include <vector>
#include <algorithm> // For std::remove

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        // Use std::remove to move all elements not equal to val to the front
        auto newEnd = std::remove(nums.begin(), nums.end(), val);

        // Erase the "removed" elements from the vector
        nums.erase(newEnd, nums.end());

        // Return the new length of the vector
        return nums.size();
    }
};
