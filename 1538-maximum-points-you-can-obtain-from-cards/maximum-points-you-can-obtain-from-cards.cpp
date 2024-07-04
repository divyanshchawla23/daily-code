class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int left = 0;
        int right = 0 ;
        int maxi  = 0;
        int rightIndex = nums.size()-1;

        for(int i =0;i<k;i++){
            left += nums[i];
            maxi  = left;
        }


        for(int i = k -1 ; i>=0;i--){
            left -= nums[i];
            right = right + nums[rightIndex];
            rightIndex = rightIndex - 1;

            maxi = max(maxi , left + right);

        }

        return maxi ;
        
    }
};