class Solution {
private:
    int f(int n, int target , vector<int>& nums){
        
        if(n==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==0 || target==nums[0]) return 1;
            return 0;
        }

        int notPick = f(n-1,target,nums);
        int pick = 0;
        if(target>=nums[n]) pick = f(n-1,target-nums[n],nums);

        return pick+notPick;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(auto it: nums){
            totalSum+=it;
        }
        int res = (totalSum-target);

        if(res % 2 != 0 || res < 0){
            return 0;
        }
        int n = nums.size();

        return f(n-1,res/2,nums);
    }
};