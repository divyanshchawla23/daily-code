class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int maxi = INT_MIN;

        sort(nums.begin(),nums.end());

        for(int i =1 ;i<nums.size();i++){
            int diff = nums[i]-nums[i-1];
            maxi = max(maxi,diff);
        }
        return maxi;

    }
};