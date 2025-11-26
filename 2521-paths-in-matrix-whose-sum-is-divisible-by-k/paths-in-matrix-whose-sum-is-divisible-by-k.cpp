class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int row, int col, vector<vector<int>>& grid, int sum, int k,
               int n, int m, vector<vector<vector<int>>>& dp) {

        if (row < 0 || col < 0 || row > n - 1 || col > m - 1) {
            return 0;
        }

        if (row == 0 && col == 0)
            return ((sum + grid[row][col]) % k == 0);

        if (dp[row][col][sum] != -1)
            return dp[row][col][sum];

        int up =
            helper(row - 1, col, grid, (sum + grid[row][col]) % k, k, n, m, dp);
        int left =
            helper(row, col - 1, grid, (sum + grid[row][col]) % k, k, n, m, dp);

        return dp[row][col][sum] = (up + left) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;

        vector<vector<vector<int>>> dp(
            n+1, vector<vector<int>>(m+1, vector<int>(k+1, -1)));

        return helper(n - 1, m - 1, grid, sum, k, n, m, dp);
    }
};