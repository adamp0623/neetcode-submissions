class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Find longest sequence that CAN be formed.
        // [10,3,4,5]
        // {2,3,4,5} is a consecutive sequence, with length 4
        // return 4.

        // Maybe we can store each value in a hash set
        // [2,20,4,10,3,4,5]
        //  start at ith element, check if nums[i] + 1 exists in the set.
        //  If it does, increase a counter, and keep following the next index
        //  until we no longer find a consecutive element. 
        // Doing this means we need to ensure that we are starting at the lowest value
        /// First check if there is a number in the set that is smaller by 1. If there is, cotinue.
        if(nums.size() == 0) return 0;
        // First create a hash set
        unordered_set<int> vals;
        for(const int num:nums) {
            vals.insert(num);
        }

        int max_length = 0;
        for(int i = 0; i < nums.size(); i++) {
            // Not at the smallest number
            if(vals.find(nums[i] - 1) != vals.end()) continue;

            // If it is the smallest number
            int length = 1;
            int target = nums[i] + 1;
            while(vals.find(target) != vals.end()) {
                length++;
                target++;
            }
            max_length = max(length, max_length);
        }
        return max_length;
    }
};
