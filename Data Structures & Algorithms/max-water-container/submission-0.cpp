class Solution {
public:
    int maxArea(vector<int>& heights) {
        
        // Two pointer approach. Start at the ends.
        // Move the left/right pointer depending on what value has a smaller height.

        // So for the example,
        // Start at the ends. Left side has a lower value, move it in. Then the right 
        // bar has a smaller value, so move that in. Do this until the pointers meet.
        // Store the maximum value seen. 

        int left = 0;
        int right = heights.size()-1;
        int max_area = 0;
        while(left < right) {
            int area = min(heights[left], heights[right]) * (right - left);
            max_area = max(max_area, area);

            if(heights[left] < heights[right]) left++;
            else right--;
        }
        return max_area;
    }
};
