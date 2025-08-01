class Solution {
private:
    int f(int n, vector<int>&nums,vector<int>&dp){

        if(n==0) return nums[0];
        if(dp[n]!=-1) return dp[n];
        
        int notPick = 0 + f(n-1,nums,dp);
        int pick = nums[n];
        if(n>1)
            pick += f(n-2,nums,dp);

        return dp[n]=max(pick,notPick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
    }
};