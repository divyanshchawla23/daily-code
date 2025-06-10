class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));

        for(int i =0;i<n;i++){
            dp[i][0] = 1;
        }

        for(int i =0;i<=amount;i++){
            dp[0][i] = (i%coins[0]==0);
        }

        for(int i =1;i<n;i++){
            for(int j = 1 ;j<=amount;j++){
                long notPick = dp[i-1][j];

                long pick =0;
                if(j>=coins[i]) pick = dp[i][j-coins[i]];
                dp[i][j] = pick+notPick;
            }
        }

        return dp[n-1][amount];
    }
};