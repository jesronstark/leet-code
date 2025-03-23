#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> currentCombination;
        std::sort(candidates.begin(), candidates.end()); // Sort to facilitate pruning and duplicate handling
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
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue; // Skip duplicates
            }
            if (candidates[i] > target) {
                break; // Further numbers will be too large
            }
            currentCombination.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i + 1, currentCombination, result);
            currentCombination.pop_back(); // Backtrack
        }
    }
};
