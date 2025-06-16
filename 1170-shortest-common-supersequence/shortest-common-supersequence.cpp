class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (str1[i] == str2[j]) {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0)
                        dp[i][j] += dp[i - 1][j - 1];
                } else {
                    int a = (i > 0) ? dp[i - 1][j] : 0;
                    int b = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = max(a, b);
                }
            }
        }

        string ans = "";
        int i = n - 1, j = m - 1;

        while (i >= 0 && j >= 0) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i--;
                j--;
            } else {
                int a = (i > 0) ? dp[i - 1][j] : 0;
                int b = (j > 0) ? dp[i][j - 1] : 0;

                if (a > b) {
                    ans += str1[i];
                    i--;
                } else {
                    ans += str2[j];
                    j--;
                }
            }
        }

        while (i >= 0) {
            ans += str1[i];
            i--;
        }

        while (j >= 0) {
            ans += str2[j];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
