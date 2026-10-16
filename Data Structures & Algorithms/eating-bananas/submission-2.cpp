class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // Need the minimum eating rate such that you can eat all the bananas within h hours.
        // h indicates the number of times you can eat from the piles. In the case that
        // h is the number of piles, then the result is just the max of the piles. 

        // if number of piles < h
        // You are allowed to visit each pile more than once, but the rate that you 
        // take from each pile is essentially bounded by the highest value in any
        // of the piles. (not very helpful since the piles can be very large)

        // Is there a way to find the right eating rate? Maybe conduct binary search
        // on all eating rates. Lets say between 1 and 25. Find the middle value:
        // 13 calculate the hours it takes. If it takes too long, make the left value
        // equal to 13. We are finding the closet value to 9.

        // [1,5,3,2] 1 and 4 
        // 2: 6 hours
        // 1: 10 hours

        if(piles.size() == h) return *max_element(piles.begin(), piles.end());
        int max_rate = *max_element(piles.begin(), piles.end());

        int left = 1;
        int right = max_rate;
        int candidate_rate;
        while(right >= left) {
            int mid = left + (right - left) / 2;
            long long hours = 0;
            for(int i = 0; i < piles.size(); i++) {
                hours += (piles[i] + static_cast<long long>(mid) - 1) / mid;
            }
            if(hours > h) {
                // Rate is too low, look in the upper half.
                left = mid + 1;
            }
            else if(hours <= h) {
                // Could be a valid candidate. But need to find the smallest rate
                // Save it.
                candidate_rate = mid;
                right = mid - 1;
            }
        }

        // This should save the last value 
        return candidate_rate;
        
    }
};
