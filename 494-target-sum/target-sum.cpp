class Solution {
public:
    int f(int ind, vector<int>& arr, int target, vector<vector<int>>& dp) {
        if (target == 0) return 1;
        if (ind == 0) return (arr[0] == target);

        if (dp[ind][target] != -1) return dp[ind][target];

        int notPick = f(ind - 1, arr, target, dp);
        int pick = 0;
        if (arr[ind] <= target)
            pick = f(ind - 1, arr, target - arr[ind], dp);

        return dp[ind][target] = pick + notPick;
    }

    int findWays(vector<int>& arr, int target) {
        int cnt = 0;
        vector<int> newArr;
        for (int x : arr) {
            if (x == 0) cnt++;      // count zeros
            else newArr.push_back(x); // keep non-zeros
        }

        int n = newArr.size();
        if (target < 0) return 0;
        if (n == 0) return (target == 0) ? pow(2, cnt) : 0;

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        int ways = f(n - 1, newArr, target, dp);
        return ways * pow(2, cnt);  // adjust for zeros
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int x = totalSum - target;
        if (x < 0 || x % 2 != 0) return 0;
        return findWays(nums, x / 2);
    }
};
