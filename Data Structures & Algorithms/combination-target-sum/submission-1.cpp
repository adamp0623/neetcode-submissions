class Solution {
public:
    // 
    // [2,5,6,9] target 9
    // Combination: 
    // Res: [2,2,2,2] b1: 2 b2: 4 b3: 6 b4: 8 
    void backtrack(vector<int>& nums, int target, vector<int>& combination, vector<vector<int>>& res, int current_sum, int idx) {
        if(idx == nums.size()) {
            return;
        }
        combination.push_back(nums[idx]);
        current_sum += nums[idx];

        if(current_sum == target) {
            res.push_back(combination);
            //combination.pop_back();
            //return;
        }
        else if(current_sum < target) {
            backtrack(nums, target, combination, res, current_sum, idx);
        }

        combination.pop_back();
        backtrack(nums, target, combination, res, current_sum - nums[idx], idx + 1);

        return;
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // We have a target
        // You can draw from the list of nums (and even the same number more than once)
        // to create the sum. 
        // We have the return the UNIQUE combinations of these numbers that sum to the target.
        // Combinations are the same if they contain the same frequency of numbers between them.

        // We can walk down the list of numbers. 
        // We keep track of what index we are on the list.
        // At the index: We add nums[i] to subset keeping track of the target.
        // If we exceed the target, we backtrack.
        // We pop the top of the subset, increase the index to try another number

        // If we reach the target value, we save that subset.
        // If the index reaches the end of nums, we return. 
        // At the end of the function, means we didnt find target, backtrack.
        // [2,5,6,9] target = 9
        // Recursively call backtrack
        // Subset: [2,2,2] exceeds, backtrack by popping the top, increment index.
        vector<int> combination;
        vector<vector<int>> res;
        int current_sum = 0;
        int idx = 0;
        backtrack(nums, target, combination, res, current_sum, idx);
        return res;
    }
};
