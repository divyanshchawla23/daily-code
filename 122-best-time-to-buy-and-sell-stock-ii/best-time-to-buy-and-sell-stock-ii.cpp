class Solution {
public:
    int solver(int ind, bool canBuy, vector<int>& prices,int n,vector<vector<int>>&dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][canBuy]!=-1){
            return dp[ind][canBuy];
        }
        int profit =0;
        if(canBuy){
            profit = max(-prices[ind] + solver(ind+1,0,prices,n,dp) , solver(ind+1,1,prices,n,dp));
        }
        else{
            profit = max(prices[ind]+solver(ind+1,1,prices,n,dp) , solver(ind+1,0,prices,n,dp));
        }

        return dp[ind][canBuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solver(0,1,prices,n,dp);
    }
};