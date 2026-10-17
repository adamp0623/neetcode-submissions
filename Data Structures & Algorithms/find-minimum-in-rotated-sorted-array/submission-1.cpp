class Solution {
public:
    int findMin(vector<int> &nums) {
        // The min value will always be after the max value if its been rotated
        // less than n times.
        // All the nums are unique, and originally sorted in increasing order.
        // Maybe we can search for two indexes that are adjacent, and decreasing. 
        // like for [3,4,5,6,1,2] if we find 6 -> 1, then the min value is 1.
        //          [6,1,2,3,4,5]

        //          

        // So we are searching for two indexes that are decreasing. 
        // Binary search, look at the mid point. If its larger than then right pointer, 
        // then the min is on the right side. If its smaller than the right pointer, 
        // then the min value is to the left. 

        int left = 0;
        int right = nums.size() - 1;
        int min_val;

        // [4,5,0,1,2,3]
        while (right > left) {
            int mid = left + (right - left) / 2;
            if(mid != 0 && nums[mid - 1] > nums[mid]) return nums[mid];
            if(nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else if(nums[mid] < nums[right]){
                right = mid;
            }
        }

        return nums[left];
    }
};
