class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // You can make a greedy decision that the smallest number seen so far will not be in the 
        // solution set. Maybe keep track of the lowest youve seen, 
        // [2, -3, 4, -2, 2, -5, -1, 4] say you are at 2. Lowest is 2, but add it.
        // Then you find -3, thats lower. Save the subarray sum [2]. Then skip -3, and 
        // start after 3
        // [1,2,3,1,-1]

        // [-1,-1,-1,0,1]
        // Maybe always restart the count if you find a value that is larger than the running sum.

        int sum = nums[0];
        int max_sum = nums[0];
        for(int r = 1; r < nums.size(); r++) {
            sum = max(nums[r], sum + nums[r]);
            max_sum = max(max_sum, sum);
        }

        return max_sum;
    }
};
