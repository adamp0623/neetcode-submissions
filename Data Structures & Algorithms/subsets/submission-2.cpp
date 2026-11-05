class Solution {
public:
// We build every subset by building every combination 
// of excluding or including each element in the list
// Decision Tree.

// 
// [1,2,3] [1,2] [1,3] [1] [2, 3] [2] [3] []

    void dfs(vector<int>& nums, vector<int>& subset, vector<vector<int>>& res, int idx) {
        if(idx == nums.size()) {
            // If you reached the end of the list, add the subset to the result
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        dfs(nums, subset, res, idx + 1); // This will recursively call until the end of the list.
        // Need to backtrack, by removing the element added at this recusive call idx.
        subset.pop_back();
        dfs(nums, subset, res, idx + 1);
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // Essentially need to propogate down the list, choosing to either include 
        // each element, or not. This forms a decision tree.
        vector<int> subset;
        vector<vector<int>> res;
        int idx = 0;
        dfs(nums, subset, res, idx);
        return res;
    }
};
