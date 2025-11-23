class Solution {
public:
    int helper(int i, int sum, vector<int>& nums, int n,vector<vector<int>>&dp){
        if(i>=n){
            if(sum==0) return 0;
            else return INT_MIN;
        }

        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }

        int pick = nums[i]+helper(i+1,(sum+nums[i])%3,nums,n,dp);
        int notPick = helper(i+1,sum,nums,n,dp);

        return dp[i][sum]=max(pick,notPick);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(4,-1));

        return helper(0,0,nums,n,dp);
    }
};