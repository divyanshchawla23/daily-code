class Solution {
private:
    int f(int n, vector<int>& nums,vector<int>& dp){
        if(n==0) return nums[0];
        if(n<0) return 0;

        if(dp[n]!=-1) return dp[n];

        int pick = nums[n]+f(n-2,nums,dp);
        int notPick = 0+f(n-1,nums,dp);

        return dp[n]=max(pick,notPick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];  // Edge case: only 1 house
    
        vector<int> temp1;
        vector<int> temp2;
        for(int i =0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        int t1 = temp1.size();
        int t2= temp2.size();
        vector<int> dp1(t1,-1);
        vector<int> dp2(t2,-1);

        return max(     f(t1-1, temp1,dp1),    f(t2-1, temp2,dp2)   );
    }
};