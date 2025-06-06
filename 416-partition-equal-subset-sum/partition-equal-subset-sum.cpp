class Solution {
private:
    bool f(int sum, int index, vector<int>& nums,vector<vector<int>> &dp){
        if(index == 0) return (nums[0]==sum);
        if(sum==0) return true;

        if(dp[index][sum]!=-1) return dp[index][sum];

        bool notTake = f(sum,index-1,nums,dp);
        bool take = false;
        if(sum>=nums[index]) take = f(sum-nums[index],index-1,nums,dp);

        return dp[index][sum] = (notTake||take);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i =0;i<n;i++){
            sum+= nums[i];
        }
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        if(sum%2!=0) return false ;
        
        else return f(sum/2,n-1,nums,dp);

        //for()
    }
};