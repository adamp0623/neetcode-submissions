class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // n integers in the range [0,n], no duplicates there is a single number that is missing. Need to return the number that is missing. The numbers are not neccessarily in order. One way would be to sort nums, then walk up the array making sure that each number only increases by one each time. That would be O(nlogn)

        // Can do without sorting? 
        // [0,1,2,3,5] This is missing the integer four.
        // Maybe we can use the sum. We know how big 0 - n would be.
        // its 0 + 1 + 2 + 3 + 4 + 5 = 15.
        // We can maybe add up all the values in nums, 0 + 1 + 2 + 3 + 5 = 11
        // 15 - 11 = 4.
        
        int n_total = 0;
        // If nums = [0,1,2,3,5] n = 5, need 
        for(int i = 0; i <= nums.size(); i++) {
            n_total += i;
        }

        int nums_total = 0;
        for(int num:nums) nums_total += num;

        return n_total - nums_total;

    }
};
