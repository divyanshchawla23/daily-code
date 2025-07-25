class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> st;
        int neg = INT_MIN;
        bool hasZero = 0;
        for (auto& it : nums) {
            if (it == 0)
                hasZero = 1;
            else if (it > 0)
                st.insert(it);
            else if (it < 0 && it > neg) {
                neg = it;
            }
        }
        int ans = 0;
        for (auto it : st) {
            ans += it;
        }
        if (ans == 0) {
            if (hasZero)
                return 0;
            else
                return neg;

        } else
            return ans;
    }
};