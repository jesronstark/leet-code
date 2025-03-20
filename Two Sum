#include <unordered_map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Create a hash table to store the complement and its index
        std::unordered_map<int, int> numToIndex;
        
        // Iterate over the array
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the hash table
            if (numToIndex.find(complement) != numToIndex.end()) {
                // If found, return the indices
                return {numToIndex[complement], i};
            }
            
            // Otherwise, add the current number and its index to the hash table
            numToIndex[nums[i]] = i;
        }
        
        // If no solution is found, return an empty vector
        return {};
    }
};
