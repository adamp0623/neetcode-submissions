class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;

        for(int i = 0; i < nums.size(); i++) {
            int partner = target - nums[i];
            if(seen.find(partner) != seen.end()) {
                return {seen[partner], i};
            }
            seen[nums[i]] = i;
        }
    }
};
