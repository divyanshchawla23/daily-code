class Solution {
public:
    int helper(int n, vector<int>&nums, int target,vector<vector<int>>&dp){
        
        if(target==0) return 1;
        if(n==0) return (target==nums[0]);
        
        if(dp[n][target]!=-1) return dp[n][target];
        
        int notPick = helper(n-1,nums,target,dp);
        int pick =0;
        if(target>=nums[n]) pick = helper(n-1,nums,target-nums[n],dp);
        
        return dp[n][target] = notPick+pick;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        vector<int> nums;
        int cnt =0;
        for(auto&it:arr){
            if(it==0) cnt++;
            else{
                nums.push_back(it);
            }
        }
        int n = nums.size();
        if(n==0){
            if(target==0){
                return pow(2,cnt);
            }else return 0;
        }
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans = helper(n-1,nums,target,dp);
        return pow(2,cnt)*ans;
    }
    int countPartitions(vector<int>& arr, int d) {
        int tot = 0;
        for(auto&it:arr){
            tot+=it;
        }
        int x = tot-d;
        if(x<0 || x%2!=0) return 0;
        return perfectSum(arr,x/2);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};