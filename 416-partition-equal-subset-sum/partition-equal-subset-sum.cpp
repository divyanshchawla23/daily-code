class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i =0;i<n;i++){
            sum+= nums[i];
        }
        vector<vector<bool>> dp(n,vector<bool>(sum/2+1,false));
        if(sum%2!=0) return false ;
        else{
            for(int i =0;i<n;i++){
                dp[i][0]=true;
            }
            if (nums[0] <= sum/2) dp[0][nums[0]] = true;

            for(int i =1;i<n;i++){
                for(int j =1;j<=sum/2;j++){
                    bool notTake = dp[i-1][j];
                    bool take = false;
                    if(j>=nums[i]) take = dp[i-1][j-nums[i]];
                    
                    dp[i][j] = (notTake||take);
                }
            }
            return dp[n-1][sum/2];

        }

    }
};