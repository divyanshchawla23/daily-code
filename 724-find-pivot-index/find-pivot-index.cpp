class Solution {
public:
    int summ(vector<int> & nums){
        int ans=0;
        for(int i =0;i<nums.size();i++){
            ans += nums[i];
        }
        return ans;


    }
    int pivotIndex(vector<int>& nums) {
        int right =  summ(nums);
        cout <<right;
        int left =0;

        for(int i =0;i<nums.size();i++){
            right -= nums[i];
            if (left == right) return i;
            left+=nums[i];
        }
        return -1;
    }
};