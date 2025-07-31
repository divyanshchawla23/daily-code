class Solution {
public:
    int helper(int n, int m, vector<vector<int>>& dp) {

        if (n < 0 || m < 0)
            return 0;
        if (n == 0 && m == 0)
            return 1;
        
        if(dp[n][m]!=-1) return dp[n][m];

        int up = helper(n - 1, m, dp);
        int left = helper(n, m - 1, dp);

        return dp[n][m]=up + left;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, dp);
    }
};