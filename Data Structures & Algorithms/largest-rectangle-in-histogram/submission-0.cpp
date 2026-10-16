class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Need to find largest rectangle that can be formed
        // In a given range [], the height is limited by shortest bar in that range.
        // If you have decreasing 

        // [7,1,7,2,2,4]
        // [2,5,6,3,4]
        // stck: [0,3,]
        // left bound: [-1, 0, 1, 0, 3]
        // Prefix Min: [-1,-1, 1, 1, 1, 4]
        // Suffix Min: [1, -1, 3, 6, 6, 6]

        vector<int> left_bound(heights.size());
        vector<int> idx_stack;
        for(int i = 0; i < heights.size(); i++) {
            while(!idx_stack.empty() && heights[idx_stack.back()] >= heights[i]) {
                idx_stack.pop_back();
            }

            if(!idx_stack.empty()) left_bound[i] = idx_stack.back();
            else left_bound[i] = -1;

            idx_stack.push_back(i);
        }

        vector<int> right_bound(heights.size());

        while(!idx_stack.empty()) idx_stack.pop_back();
        
        for(int i = heights.size() - 1; i >= 0; i--) {
            while(!idx_stack.empty() && heights[idx_stack.back()] >= heights[i]) {
                idx_stack.pop_back();
            }

            if(!idx_stack.empty()) right_bound[i] = idx_stack.back();
            else right_bound[i] = heights.size();

            idx_stack.push_back(i);
        }

        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            left_bound[i] += 1;
            right_bound[i] -= 1;
            maxArea = max(maxArea, heights[i] * (right_bound[i] - left_bound[i] + 1));

        }

        return maxArea;


        
    }
};
