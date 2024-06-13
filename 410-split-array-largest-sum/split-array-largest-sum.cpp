class Solution {
public:

    int partitions(vector<int>& nums, int mid){
        int part = 1;
        int sum = 0;

        for (int i =0;i<nums.size();i++){
            if (sum + nums[i]>mid){
                part += 1;
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
        }
        return part ;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        while(low<=high){
            int mid = (low +high) /2;

            if (partitions(nums, mid)<=k){
                ans = mid ;
                high = mid -1 ;
            }
            else {
                low = mid +1;
            }
        }
        return ans ;
    }
};