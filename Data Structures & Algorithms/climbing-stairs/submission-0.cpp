class Solution {
public:
    // The solution for n = 2 builds off the solution for n = 1
    // n = 1 (1)
    // n = 2 (1 + 1, or 2)
    // n = 3 ((1 + 1) + 1, (2) + 1, 1 + (2)
     int climbStairs(int n) {
        // Its always the number of ways to get to n - 1 plus the number of ways to 
        // get to n - 2.
        if(n <= 2) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
