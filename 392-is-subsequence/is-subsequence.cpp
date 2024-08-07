class Solution {
public:

    int helper(string s1, string s2 ,int n ,int m ){
        int dp[n+1][m+1];
        
        for(int i =0;i<=n;i++){
            for(int j =0;j<=m;j++){
                if(i==0||j==0) dp[i][j]=0;
            }
        }

        for(int i =1;i<=n;i++){
            for(int j =1;j<=m;j++){
                if(s1[i-1]==s2[j-1])  dp[i][j] = 1 + dp[i-1][j-1];
                else  dp[i][j] = max( dp[i][j-1],dp[i-1][j] );
            }
        }

        return dp[n][m];

        
    }
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        int ans = helper(s,t,n,m);

        if(ans==n) return true ;
        else return false;
    }
};