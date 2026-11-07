class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    void backtrack(string s, vector<string>& subset, vector<vector<string>>& res) {
        // Base case conditions
        if(s.size() == 0) {
            res.push_back(subset);
            return;
        }

        for(int i = 1; i <= s.size(); i++) {
            // Need to try splitting the string.
            if(isPalindrome(s.substr(0, i))) {
                // This is valid, so add it to the subset,
                subset.push_back(s.substr(0, i));
                backtrack(s.substr(i), subset, res);
                // Remove it so you can try other splits
                subset.pop_back();
            }
        }


    }
    vector<vector<string>> partition(string s) {
        // Each element in the result needs to contain a different way to split
        // up the string s where each substring is a palindrome. 

        // You can either split at the current index, or skip this index. 
        // You can have at most len(s) - 1 splits. 
        // If the current string is a palindrome, and theres been at least one
        // split, you can save that string as a palindrome. 
        // If the split idx has moved past the string, add to the result.

        // "aab" If you split at idx 1, "a|ab", calling backtrack("ab") will find
        // all the palindrome combinations with a split at idx = 1. 
        vector<string> subset;
        vector<vector<string>> res;
        backtrack(s, subset, res);
        return res;

    }
};
