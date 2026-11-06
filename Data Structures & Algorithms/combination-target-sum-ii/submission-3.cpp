class Solution {
public:
    void backtrack(vector<int> nums, vector<int>& combo, int cur_sum, int idx, int target, vector<vector<int>>& res) {
        if(idx == nums.size()) {
            return;
        }

        combo.push_back(nums[idx]);
        cur_sum += nums[idx];

        // If the target is greater than the cur sum already, dont explore future paths.
        if(cur_sum > target) {
            combo.pop_back();
            return;
        }
        else if(target == cur_sum) {
            // The candidate we added is a valid combination.
            res.push_back(combo);
        }
        else{
            // If the current sum is less than the target, we need to go deeper, leaving
            // the current candidate in the path.
            backtrack(nums, combo, cur_sum, idx + 1, target, res);
        }
        
        // We reach this point in three ways.
        // First if a combo has been found, we should leave this current value out and look for more.
        // Second after we explore all the paths that include the current node, look at the paths      // without this node.
        combo.pop_back();
        // The next item I choose, might be the same value. If the next value in line is the same,
        // I should skip that one too.
        cur_sum -= nums[idx];
        while((idx < nums.size() - 1) && nums[idx] == nums[idx + 1]) idx++;
        backtrack(nums, combo, cur_sum, idx + 1, target, res);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Candidates may contain duplicates.
        // Can only draw from candidates at most once. 
        // Result set cant have duplicate combinations, so combinations
        // that have the same frequency of numbers.

        // Need to do DFS and backtracking in a similair manner to the previous question
        // Start a DFS at the node, if you overshoot, remove that number, and do a DFS
        // without that number.
        // [9,1] Start at 9. Add it to the subset, and current_sum. If its too big,
        // need to do another DFS without it.
        // Treat the DFS like it works already. How would you do it.
        // Base cases: If the idx gets past the candidates, return.
        //             if the sum reaches the target, add it to result.
        //             if you overshoot the target, skip that value.
        // Two different paths can create two of the same combinations because you can draw 
        // the same value in two different paths.

        sort(candidates.begin(), candidates.end());
        vector<int> combo;
        vector<vector<int>> res;
        int idx = 0;
        int cur_sum = 0;
        backtrack(candidates, combo, cur_sum, idx, target, res);
        return res;
    }
};
