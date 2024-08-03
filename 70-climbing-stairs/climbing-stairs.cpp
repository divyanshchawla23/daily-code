class Solution {
public:
        int dp[46];
    int climbStairs(int n) {
        if (n <= 1) return 1;
        
        dp[0] = 1; // Base case: 1 way to climb 0 stairs (do nothing)
        dp[1] = 1; // Base case: 1 way to climb 1 stair

        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
};
