class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        if(nums.size()==1){
            return nums[0];
        }
        int n = nums.size();
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-2]!=nums[n-1]) return nums[n-1];
        int start = 1;
        int end = n-2;

        while(start<= end){

            int mid = (start + end) /2;

            if (nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }

            else if(mid%2==0 && nums[mid]==nums[mid+1]
            ||
            mid %2 == 1 && nums[mid]==nums[mid-1]){
                start = mid+1;
            }


            else {
                end = mid -1;
            }
            
        }

        return -1;
    }
};