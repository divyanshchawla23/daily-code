class Solution {
private:
    int f(int n, int m ,string s, string t,vector<vector<int>>& dp){
        if(n<0 || m<0) return 0;

        if(dp[n][m]!=-1) return dp[n][m];

        if(s[n]==t[m]) return dp[n][m] = 1 + f(n-1,m-1,s,t,dp);
        else return dp[n][m]=max(f(n,m-1,s,t,dp),f(n-1,m,s,t,dp));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));

        int lcs = f(n-1,m-1,word1,word2,dp);

        return (n-lcs)+(m-lcs);
    }
};