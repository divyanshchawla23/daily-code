class Solution {
public:
    int mod = 1e9 + 7;
    void fillStates(int index, string& s, vector<string>& states, int n) {
        if (index >= 3) {
            states.push_back(s);
            return;
        }

        for (auto it : {'R', 'Y', 'G'}) {
            if (!s.empty() && s.back() == it) {
                continue;
            } else {
                s += it;
                fillStates(index + 1, s, states, n);
                s.pop_back();
            }
        }
    }
    int solve(int n, int prevInd, vector<string>& states,vector<vector<int>> &dp) {
        if (n == 0)
            return 1;

        if(dp[n][prevInd]!=-1) return dp[n][prevInd];

        int res = 0;

        string last = states[prevInd];

        for (int curr = 0; curr < 12; curr++) {
            if (curr == prevInd)
                continue;

            string currPattern = states[curr];

            bool conf = 0;

            for (int col = 0; col < 3; col++) {
                if (currPattern[col] == last[col]) {
                    conf = 1;
                    break;
                }
            }

            if (!conf) {
                res = (res + solve(n - 1, curr, states,dp)) % mod;
            }
        }

        return dp[n][prevInd]=res;
    }
    int numOfWays(int n) {
        vector<string> states;
        string s = "";
        fillStates(0, s, states, n);

        int res = 0;
        vector<vector<int>> dp(n+1,vector<int>(13,-1));

        for (int i = 0; i < 12; i++) {
            res = (res + solve(n - 1, i, states,dp)) % mod;
        }

        return res;

        return -1;
    }
};