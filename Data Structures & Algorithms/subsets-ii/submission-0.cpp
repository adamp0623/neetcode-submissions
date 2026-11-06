class Solution {
public:
    void backtrack(vector<int> nums, int idx, vector<int>& subset, vector<vector<int>>& res) {
        if(idx == nums.size()) {
            res.push_back(subset);
            return;
        }

        // Choose the value at this idx
        subset.push_back(nums[idx]);
        // Find all the subsets containing this idx.
        backtrack(nums, idx + 1, subset, res);

        // Remove this value from the subset.
        subset.pop_back();
        // And also need to skip all other values that match the current one.
        while(idx != nums.size() - 1 && nums[idx] == nums[idx+1]) idx++;
        // Find the subsets not containing the current idx, and any value that matches it.
        backtrack(nums, idx + 1, subset, res);
        return;

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Two choices at each index, leave the current number in the subset, or leave it out.
        // Once you decide to leave it out, you need to make sure that you leave out its duplicate
        // value aswell. Sort first so duplicate values are adjacent.
        // A call of backtrack() at a specific value will find all the subsets containing that value.

        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> res;
        int idx = 0;
        backtrack(nums, idx, subset, res);
        return res;

    }
};
