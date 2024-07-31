class Solution {
public:
    int dp [1001][1001];

    int helper(string text1, string text2, int n , int m){

        
        for(int i =0;i<n+1;i++){
            for(int j =0;j<m+1;j++){
                if(i==0||j==0) dp[i][j]=0;
            }
        }
        for(int i =1;i<n+1;i++){
            for(int j =1;j<m+1;j++){
               if(text1[i-1]==text2[j-1]){
                dp[i][j]=  1+dp[i-1][j-1];
               }
               else  dp[i][j]= max(dp[i][j-1], dp[i-1][j]);
            }
        }


        return dp[n][m];

    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        int n = text1.size();
        int m = text2.size();

        return helper(text1, text2, n ,m);


        
    }
};