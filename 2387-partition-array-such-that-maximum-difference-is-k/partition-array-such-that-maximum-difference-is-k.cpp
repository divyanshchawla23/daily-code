class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int cnt = 1;

        int num = nums[0];

        for(int i =1;i<nums.size();i++){
            if(nums[i]-num>k){
                cnt++;
                num = nums[i];
            }
        }


        return cnt;
    }
};