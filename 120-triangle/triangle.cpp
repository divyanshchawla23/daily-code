class Solution {
private:
    int f(int row,int col,int n, vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(row == n-1){
            return triangle[n-1][col];
        }

        if(dp[row][col]!=-1) return dp[row][col];

        int down = triangle[row][col] + f(row+1,col,n,triangle,dp);
        int diag = triangle[row][col] + f(row+1,col+1,n,triangle,dp);

        return dp[row][col] = min(down,diag);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return f(0,0,n,triangle,dp);
    }
};