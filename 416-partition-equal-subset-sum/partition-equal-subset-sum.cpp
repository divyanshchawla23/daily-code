class Solution {
public:
    bool helper(int n, vector<int>&nums,int k,vector<vector<int>>&dp){
        if(k==0) return true;
        if(n==0) return (nums[n]==k);
        if(dp[n][k]!=-1) return dp[n][k];

        bool notPick = helper(n-1,nums,k,dp);
        bool pick = false;
        if(nums[n]<=k) pick = helper(n-1,nums,k-nums[n],dp);

        return dp[n][k] = (notPick||pick);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(auto &it: nums){
            sum+=it;
        }
        vector<vector<int>>dp(n,vector<int>(sum+1,-1));
        if(sum%2!=0) return false;
        else return helper(n-1,nums,sum/2,dp);
    }
};