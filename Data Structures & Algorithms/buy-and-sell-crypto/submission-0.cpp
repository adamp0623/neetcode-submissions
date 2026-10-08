class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // For buying the stock, we need to know if there are cheaper prices 
        // For selling the stock, we need to know if there are more expensive prices

        // Use some sort of two pointer approach.
        // [10,1,5,6,7,1] 
        // Need to find the min value, and max value, and ensure the min value is before the 
        // max value. 
        // BruteForce: Check every value with every other value, and find the max profit, 
        // ensuring the buy date is after the sell date. 
        // Just need the max value, and min value, ensuring the min comes before the max.

        // We essentially want an optimal window.
        // We can have two pointers that start at the beginning, and we need to advance
        // the right pointer looking for maximum values, and we need to advance the left
        // pointer if there are cheaper options to buy in the future. 
        // As the right advances, store the cheapest price seen. If the left pointer
        // is at a value greater than that, move it in, to look for the cheaper price.
        // Calculate profit at each point? Take max.

        // [10, 2, 5, 6, 1]
        int max_profit = 0;
        int lowest_seen = prices[0];
        int left = 0;
        // Advance the right side, updating the lowest seen value. 
        for(int right = 1; right < prices.size(); right++) {
            
            lowest_seen = min(lowest_seen, prices[right]);
            while(prices[left] != lowest_seen) {
                // If the left pointer is not at the lowest seen price. 
                // Keep bringing it in until it reaches that value.
                left++;
            }
            if(left < right) max_profit = max(max_profit, prices[right] - prices[left]);
            
        }
        return max_profit;
    }
};
