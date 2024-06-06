class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // MOORES VOTING ALGORITHM

        int cnt =0;
        int el ;

        for (int i =0;i<nums.size();i++){
            if (cnt ==0){
                el = nums[i];
                cnt++;
            }
            else if(nums[i]== el){
                cnt ++;
            }

            else if(nums[i] != el){
                cnt --;
            }
        }

        int cnt1 =0;

        for (int i =0;i<nums.size();i++){
            if (nums[i]== el){
                cnt1++;
            }

        }
        if (cnt1>nums.size()/2){
            return el ;
        }

        return -1;

        
        
    }
};