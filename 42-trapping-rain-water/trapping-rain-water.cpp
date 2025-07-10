class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int l =0;
        int r = n-1;
        int leftMax = -1;
        int rightMax = -1;

        while(l<r){
            leftMax = max(leftMax,height[l]);
            rightMax = max(rightMax,height[r]);

            if(leftMax<rightMax){
                ans+=leftMax-height[l];
                l++;
            }else{
                ans+=rightMax-height[r];
                r--;
            }
        }

        return ans;
    }
};