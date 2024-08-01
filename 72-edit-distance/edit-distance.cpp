class Solution {
public:
    int dp[501][501];

    int helper(string s1 , string s2 , int n , int m){
        if(n==0) return m;
        if(m==0) return n;
        if(dp[n][m]!=-1) return dp[n][m];

        if(s1[n-1]==s2[m-1]) return  dp[n][m]= helper(s1,s2,n-1,m-1);

        else 
        return dp[n][m]= 1 + min( min(helper(s1,s2,n-1,m-1),helper(s1,s2,n,m-1)),helper(s1,s2,n-1,m) );
    }

    int minDistance(string word1, string word2) {
      memset(dp,-1,sizeof(dp));
      int n = word1.size();
      int m = word2.size();

      return helper(word1,word2, n , m);



    }
};