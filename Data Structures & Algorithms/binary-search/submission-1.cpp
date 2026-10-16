class Solution {
public:
    int search(vector<int>& nums, int target) {

        // [-1, 0, 2,4,6,8]
        // [4]
        int left = 0;
        int right = nums.size() - 1;


        while(right >= left) {
            int mid = left + (right - left) / 2;

            if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
            }
            else {
                return mid;
            }
        }
        
        return -1;
        
    }
};
