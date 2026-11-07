class Solution {
public:
    void backtrack(string digits, unordered_map<int, string> letters, int idx, string& subset, vector<string>& res) {
        // Base case if idx reaches the end
        if(digits.size() == 0) {
            return;
        }
        if(idx == digits.size()) {
            res.push_back(subset);
            return;
        }
        string choices = letters[stoi(digits.substr(idx, 1))];
        for(int i = 0; i < choices.size(); i++) {
            subset.push_back(choices[i]);
            backtrack(digits, letters, idx + 1, subset, res);
            subset.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        // Given list of digits 2 through 9
        // Each digit can represent 3 characters. Ex: 2 can be a, b, or c.
        // Need to return every possible letter combination that the string digits
        // could be.
        // Ex, digit 3: you can choose d, e or f.
        // Or digit 7: you can choose pqrs.

        // For each recursive call, pull from the letter map for which digit you are on.
        // Loop across each letter, to choose that letter.
        // Recurse with idx + 1, to find all combinations of letters that include that
        // mapping for that letter.
        // Undo the choice, continue looping
        
        // Only stop if the idx has moved across all the digits.

        // First you should create a map, for O(1) lookup of what the letters could be.
        unordered_map<int, string> letters;
        // Key would be the number, value is a string of all the letters.
        // Definitely is a smarter way of doing this, but this works for now.
        letters[2] = "abc";
        letters[3] = "def";
        letters[4] = "ghi";
        letters[5] = "jkl";
        letters[6] = "mno";
        letters[7] = "pqrs";
        letters[8] = "tuv";
        letters[9] = "wxyz";

        vector<string> res;
        string subset;
        backtrack(digits, letters, 0, subset, res);
        return res;
    }
};
