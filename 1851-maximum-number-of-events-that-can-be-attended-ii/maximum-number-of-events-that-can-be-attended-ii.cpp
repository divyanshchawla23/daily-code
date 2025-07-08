class Solution {
private:
    int f(int n, vector<vector<int>> &events, int k,vector<vector<int>> &dp) {
        if (n < 0 || k == 0)
            return 0;

        int value = events[n][2];

        if(dp[n][k]!=-1) return dp[n][k];

        int notTake = f(n - 1, events, k,dp);

        int j = n - 1;
        for (; j >= 0; j--) {
            if (events[j][0] > events[n][1])
                break;
        }

        int take = value + f(j, events, k - 1,dp);
        return  dp[n][k] = max(take, notTake);
    }

public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        sort(events.rbegin(), events.rend());
        return f(n - 1, events, k,dp);
    }
};