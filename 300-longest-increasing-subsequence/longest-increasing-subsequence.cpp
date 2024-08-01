class Solution {
public:
    int helper(vector<int> nums1, vector<int> nums2,int n , int m){
        int dp[n+1][m+1];
        for(int i =0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0) dp[i][j]=0;
            }
        }

        for(int i =1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]) dp[i][j]=  1+dp[i-1][j-1];
                else{
                    dp[i][j]= max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
    int lengthOfLIS(vector<int>& nums) {
        set<int> st;
        for(int i =0;i<nums.size();i++){
        st.insert(nums[i]);
        }
        vector<int> nums2(st.begin(),st.end());
        int n = nums.size();
        int m = nums2.size();

        return helper(nums,nums2, n ,m);


        
    }
};