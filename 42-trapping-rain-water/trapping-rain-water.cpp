class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int> before(n);
        vector<int> after(n);

        before[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            before[i] = max(before[i - 1], height[i]);
        }
        after[n - 1] = height[n - 1];
        for (int i = height.size() - 2; i >= 0; i--) {
            after[i] = max(after[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++) {
            int mini = min(before[i], after[i]);
            ans += mini - height[i];
        }

        return ans;
    }
};