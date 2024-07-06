class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        int left =0;
        int right =n-1;
        int leftmax =0;
        int rightmax = 0;
        int res = 0;


        while(left<=right){

            if(nums[left]<=nums[right]){

                leftmax =max(leftmax,nums[left]);

              //  if(nums[left]>=leftmax) leftmax = nums[left];

                 res+= leftmax - nums[left];

            left++;
            }


            else{

              // if(nums[right]>=rightmax) rightmax = nums[right];
                rightmax = max(rightmax,nums[right]);

                 res+= rightmax - nums[right];

            right--; 
            }   

        

        }
        return res;
    }
};