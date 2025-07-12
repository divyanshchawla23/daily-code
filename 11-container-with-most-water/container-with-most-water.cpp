class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;

        while (left < right) {

            int water = (right - left) * min(height[right], height[left]);
            ans = max(ans, water);

            if (height[right] < height[left]) {
                right--;
            } else
                left++;
        }

        return ans;
    }
};