class Solution {
public:
    int helper(int n, vector<int>& nums, vector<int>& dp) {
        if (n == 0)
            return nums[0];
        if (dp[n] != -1)
            return dp[n];

        int notPick = helper(n - 1, nums, dp);
        int pick = nums[n];
        if (n > 1) pick += helper(n - 2, nums, dp);

        return dp[n] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> temp1;
        vector<int> temp2;
        for (int i = 0; i < nums.size() - 1; i++) {
            temp1.push_back(nums[i]);
        }
        for (int i = 1; i < nums.size(); i++) {
            temp2.push_back(nums[i]);
        }
        int n = temp1.size();
        int m = temp2.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(m, -1);

        int ans1 = helper(n - 1, temp1, dp1);
        int ans2 = helper(m - 1, temp2, dp2);

        return max(ans1, ans2);
    }
};