class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        if(nums.size() == 0) return false;

        for(const int num:nums) {
            if(seen.find(num) != seen.end()) return true;
            seen.insert(num);
        }

        return false;
    }
};