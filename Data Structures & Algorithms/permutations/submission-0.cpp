class Solution {
public:
    void backtrack(vector<int> choices, vector<int>& perm, vector<vector<int>>& res) {
        // At each step, you make a choice to draw from the "bag" of values.
        // If there are no more values to draw, you should return the permutation you made. 
        
        // [1,2,3] perm: [1,2,3]
        // [1,2,3]
        if(choices.size() == 0) {
            res.push_back(perm);
            return;
        }

        // Create a path for every possible choice
        for(int i = 0; i < choices.size(); i++) {
            int chosen = choices[i];
            // Add chosen 
            perm.push_back(chosen);
            
            // Remove chosen from range of choices to check permutations if you didnt choose it first.
            choices.erase(choices.begin() + i);
            backtrack(choices, perm, res);

            // Before choosing another, put original choice back in the range of choices.
            choices.insert(choices.begin() + i, chosen);
            perm.pop_back();
        }
        

    }

    vector<vector<int>> permute(vector<int>& nums) {
        // For permutations, order matters
        // Every permutation needs to arrange the entire array of nums. 
        // [1,2,3]
        // idx = 0,1,2
        // []
        // Drawing from a bag of marbles...
        vector<int> perm;
        vector<vector<int>> res;
        backtrack(nums, perm, res);
        return res;
    }
};
