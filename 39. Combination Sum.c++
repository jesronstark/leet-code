#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentCombination;
        std::sort(candidates.begin(), candidates.end()); // Sort to facilitate pruning
        backtrack(candidates, target, 0, currentCombination, result);
        return result;
    }

private:
    void backtrack(const std::vector<int>& candidates, int target, int start,
                   std::vector<int>& currentCombination, std::vector<std::vector<int>>& result) {
        if (target == 0) {
            result.push_back(currentCombination);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) {
                break; // Further numbers will be too large
            }
            currentCombination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, currentCombination, result);
            currentCombination.pop_back(); // Backtrack
        }
    }
};
