class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Need to determine if you can jump to the last index
        // starting from the first index.

        // At each index, you have the choice of of taking UP TO that jump length
        // If your value is zero and your index is not the last, its a dead end. 

        // You can explore every possible jump for each index, and find all the paths 
        // but that will be expensive for larger numbers. 

        // If your value is large enough, you should be able to reach the end result with one jump.
        // If your value is too small, you need to make a decision about what index to jump to.
        // You need to avoid indexes that have a value of zero, since you can get stuck there.
        // At each point, we need to make a decision that we know for sure wont lead to us landing
        // on a zero. 

        // Can you just pick any location that doesnt have a 0? 
        // But what if a non-zero choice ends up leading to a dead end? 

        // Try the other direction.
        // Starting from the end, find a value that can reach you.
        // Then move to that index. Find a value that can reach you again. 
        // What if multiple values can reach the end? Choice wouldnt matter,
        // [0,0,2,1,0]

        int current_idx = nums.size() - 2;
        int goal_idx = nums.size() - 1;
        while(current_idx >= 0) {
            if(current_idx + nums[current_idx] >= goal_idx) {
                goal_idx = current_idx;
            }
            current_idx--;
        }

        return (goal_idx == 0);

    }
};
