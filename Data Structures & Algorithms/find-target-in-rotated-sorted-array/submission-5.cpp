class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Previously searched for the minimum value. 
        // If the array is not rotated, and just sorted, can preform a regular binary serach
        // If the array is rotated, then the array will be split into two sorted portions.
        // [3,4,5,6,1,2] Theres [3,4,5,6] and [1,2] You can check left and right pointer to see
        // if you are in a sorted portion.  In this example, left ptr is 3 and right ptr is 2.
        // But if target is 4, which is larger than left pointer, then it must be on the 
        // left side. If the value is less than 3, then it must be on the right side. 
        // [3,4,1,2]
        // First check if mid is the target. If not:
        
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            if(nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) right = mid - 1;  
                else left = mid + 1;   // Search right half
            }
            else {
                    if (nums[mid] < target && target <= nums[right]) left = mid + 1;
                    else right = mid - 1;  // Search left half
            }
            
        }
        return -1;
    }
};
