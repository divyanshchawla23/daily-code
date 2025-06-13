class Solution {
private:
    int longestCommonSubsequence(string text1, string text2,int n, int m)
    {
        
        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0)
                        dp[i][j] += dp[i - 1][j - 1];
                    ;
                }
                else
                {
                    dp[i][j] = 0;

                    int a = 0;
                    int b = 0;
                    if (i > 0)
                        a = dp[i - 1][j];
                    if (j > 0)
                        b = dp[i][j - 1];

                    dp[i][j] += max(a, b);
                }
            }
        }
        return dp[n-1][m-1];
    }
public:
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());
        int n = s.size();
        int m = s1.size();
        return longestCommonSubsequence(s,s1,n,m);
    }
};