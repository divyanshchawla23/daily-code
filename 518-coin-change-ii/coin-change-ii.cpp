class Solution {
private:
    int f(int n, int target, vector<int>&coins,vector<vector<int>> &dp){
        //base case
        if(target==0) return 1;

        if(n==0){
            if(target%coins[0]==0) return 1;
            else return 0;
        } 

        if(dp[n][target]!=-1) return dp[n][target];

        long notPick = f(n-1,target,coins,dp);

        long pick =0;
        if(target>=coins[n]) pick = f(n,target-coins[n],coins,dp);

        return dp[n][target] = pick+notPick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        return f(n-1,amount,coins,dp);
    }
};