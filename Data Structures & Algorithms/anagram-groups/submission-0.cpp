class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<int>> indexes;

        for(int i = 0; i < strs.size(); i++) {
            string copy = strs[i];
            // Making sure the strings are sorted, so that anagrams will be grouped together in hash map
            sort(copy.begin(), copy.end());
            indexes[copy].push_back(i);
        }

        // Hash map should contain {"str1": [0,1], "str2":[2,3]}
        // Where str1 and str2 are anagrams, with value of original string index.
        vector<vector<string>> res;

        // Outer loops for every anagram
        for(const auto&[key, value]: indexes) {
            // Inner loops for every index for that anagram
            vector<string> temp;
            for(const int index:value) {
                temp.push_back(strs[index]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
