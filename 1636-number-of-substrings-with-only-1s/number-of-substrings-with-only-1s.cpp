class Solution {
public:
    const int mod = 1e9 + 7;
    int numSub(string s) {
        int n = s.size();
        long long ans = 0;

        long long cnt1 = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                ans = (ans + (cnt1 * (cnt1 + 1)) / 2) % mod;
                cnt1 = 0;
            } else {
                cnt1++;
            }
        }

        ans = (ans + (cnt1 * (cnt1 + 1)) / 2) % mod;

        return ans;
    }
};