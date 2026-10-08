class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Sorted in non increasing order. 
        // Numbers are sorted. 
        // [1,2,3,4]
        // Slide the right pointer until the value is less than the target.
        // Once the right side is at that value, move the left side until it reaches the pair

        int left = 0;
        int right = numbers.size() - 1;
        int partner = 0;
        
        // [1, 2,3,4]
        while(left < right) {
            int cursum = numbers[left] + numbers[right];

            if(cursum < target) left++;
            if(cursum > target) right--;
            if(cursum == target) return {left+1, right+1};
        }

        return {};
    }
};
