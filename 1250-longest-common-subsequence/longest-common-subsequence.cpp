class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(text1[i]==text2[j]){
                    dp[i][j] =  1; 
                    if(i>0 && j>0) dp[i][j] += dp[i-1][j-1];;
                }
                else{
                    dp[i][j]= 0;

                    int a=0;
                    int b=0;
                    if(i>0)  a =  dp[i-1][j];
                    if(j>0)  b =  dp[i][j-1];
                    
                    dp[i][j] += max( a,b);
                }
            }
        }

        return dp[n-1][m-1];
    }
};