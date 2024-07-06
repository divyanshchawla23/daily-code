class Solution {
public:
    int lessthan(vector<int>& nums, int goal){
        int r= 0 , l= 0 , cnt= 0 , sum = 0;
        int n = nums.size();
        if(goal<0) return 0;

        while(r<n){
            sum += nums[r];

            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;

    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int ans1 = lessthan(nums, goal);
        int ans2 = lessthan(nums, goal-1);

        return ans1-ans2;
        
    }
};