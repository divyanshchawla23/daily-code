class Solution {
public:
    int  helper(vector<int> nums , int k , int n){

	
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (i == 0) 
				dp[i][j] = 0;
			if (j == 0) 
				dp[i][j] = 1;
		}
	}
	
    
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 0; j < k+1; j++)
        {
            if (nums[i - 1] <= j) {
              dp[i][j] = (dp[i - 1][j - nums[i - 1]] + dp[i - 1][j])%1000000007;
            }

            else
              dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][k];
}
    int findTargetSumWays(vector<int>& nums, int k) {
        int n = nums.size();

        int sumOfArray = 0;
	    for (int i = 0; i < n; i++)
        {    
		sumOfArray += nums[i];  
        }
        int res =0;

        int sum = (k+sumOfArray);
        if (sum % 2 != 0 || sum < 0) return 0;

        // Find the subset sum
        return helper(nums, sum / 2, n);

    }
};