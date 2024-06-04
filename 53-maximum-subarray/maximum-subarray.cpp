class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0 ;

        for (int i =0;i<n;i++){
            sum += nums[i];

        // if (sum >0){
        //     maxi = sum;
        // }  
        maxi= max(maxi,sum);

        


        if (sum <0){
            sum = 0;
        }

        }

        // if (maxi < 0){
        //     maxi =0;
        // }

        return maxi;
    }
};