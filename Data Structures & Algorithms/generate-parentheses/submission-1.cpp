class Solution {
public: // res []
// Say n = 2. idx = 0, n_c = 2, n_open = 2, idx = 0, stack: [(], subset: [(]
// Parent call, subset empty, idx < n*2, 
// 
    void backtrack(int n_open, int n_closed, string& subset, vector<string>& res) {

        // If the idx is equal to n*2, save the subset.
        if(n_open == 0 && n_closed == 0) {
            res.push_back(subset);
            return;
        }

        // Make a choice to add a closed at this idx, or an open at this idx.
        // First choose to add a closed bracket, then revert that choice, and instead try an open.

        if(n_closed > n_open) {
            subset.push_back(')');
            backtrack(n_open, n_closed - 1, subset, res);
            // Then revert that choice
            subset.pop_back();
        }
        if(n_open > 0)  {
            subset.push_back('(');
            backtrack(n_open - 1, n_closed, subset, res);
            subset.pop_back();
        }

        return;
    }

    vector<string> generateParenthesis(int n) {
        // Need to generate a valid parentheses string that can be generated with n pairs of 
        // parenthesis.
        // A valid parenthesis string has every opened bracket matched with a closed bracket.
        // You cant create a new open bracket
        // With n pairs of paranthesis, you have n open brackets to choose and n closed brackets to 
        // choose.
        // You need to make n*2 total selections.
        // You can make every possible choice, and use a stack to check if the resulting
        // string is a valid paranthesis. You do this with a stack. If you open a bracket, you
        // add it to the stack. If you close a bracket, check if there is an open bracket
        // at the top of the stack to match it with. If theres a match, pop the open bracket 
        // from the stack. If you try to close a bracket with the stack empty, its invalid, 
        // return immediately.
        // Lets say you have n = 3
        // You have three opens and three closed to choose from.
        // Just make sure you are not closing a bracket if the
        // running stack is empty. If the stack is not empty, pop the top of the stack
        // (())()
        vector<string> res;
        string subset;
        int n_open = n;
        int n_closed = n;
        backtrack(n_open, n_closed, subset, res);
        return res;

    }
};
