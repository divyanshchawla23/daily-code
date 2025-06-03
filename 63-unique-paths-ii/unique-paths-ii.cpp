class Solution {
private:
    int f(int n, int m, vector<vector<int>>& grid,vector<vector<int>> &dp){

        if(n>=0 && m>=0 && grid[n][m]==1) return 0;
        if(n==0 && m==0 ) return 1;
        if(n<0 || m<0) return 0;

        if(dp[n][m]!=-1) return dp[n][m];

        int left = f(n,m-1,grid,dp);
        int up = f(n-1,m,grid,dp);

        return dp[n][m]= left+up;

    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,obstacleGrid,dp);
    }
};