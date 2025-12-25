class Solution {
public:
    long long maximumHappinessSum(vector<int>& hh, int k) {
        sort(hh.begin(), hh.end(), greater<int>());
        int cnt = 0;
        long long ans = 0;

        for (int i = 0; i < k; i++) {
            ans += max(hh[i] - cnt, 0);
            cnt++;
        }

        return ans;
    }
};