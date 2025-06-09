class Solution {
private:
    int f(int n, int amount, vector<int> &coins,vector<vector<int>> &dp){
        if(amount == 0) return 0;

        if(n==0){
            if(amount%coins[n] == 0) return amount/coins[0];
            else return 1e9;
        }

        if(dp[n][amount]!=-1) return dp[n][amount];

        int notTake = 0 + f(n-1,amount,coins,dp);
        int take = INT_MAX;
        if(amount>=coins[n]) take = 1 + f(n,amount-coins[n],coins,dp);

        return dp[n][amount] = min(notTake,take);

    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(n - 1, amount, coins,dp);  // FIXED: using correct index
        return (ans >= 1e9) ? -1 : ans;
        
    }
};