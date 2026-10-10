class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // Sliding window fixed size k 
        // Need to return a vector of the maximums for each time the window slides one step.
        // [|1,2,1|,0,4,2,6]
        // 2,2,4
        // Easiest way to do this, move the window across, iterating through the window every time
        // to find what the maximum is. O(n)

        // We want O(1) insertion, O(1) retrieval of max, and be able to dequeue the first entered
        // item. Just using a priority queue allows for the first two but not the last.
        // We can use a regular queue for tracking what to remove, and a prioritiy queue for 
        // the maximum
        // Priority Q: 2, 1, 1
        // How to update the priority queue? 
        // The max value of the priority queue needs to be changed in a couple cases
        // The max value is out of the window range, or there is a new value thats larger just added.
        //
        // When a new element is added, check if its larger than the front of PQ. If so, 
        // update the  PQ. When window reaches size, save the top of the PQ to result.
        // check the back element of DQ, if its the same value as the top of the PQ, remove the top.

        vector<int> max;
        priority_queue<pair<int,int>> max_heap;

        // [|1,2,1|,0,4,2,6]
        // PQ: 2,1,1
        // DQ: 1,2,1
        // Max : 

        for(int right = 0; right < nums.size(); right++) {
            
            max_heap.push({nums[right], right});

            if(right >= k - 1) {
                while(max_heap.top().second <= right - k) {
                    max_heap.pop();
                }
                max.push_back(max_heap.top().first);
            }
            
        }
        return max;
    }
};
