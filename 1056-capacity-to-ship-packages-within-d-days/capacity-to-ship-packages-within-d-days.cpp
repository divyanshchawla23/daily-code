class Solution {
public:
    

    int numberOfDays(vector<int>& nums, int mid){
        int days =1;
        int weight=0;

        for(int i =0;i<nums.size();i++){
            if (weight+nums[i]>mid){
                days = days +1;
                weight = nums[i];
            }
            else{
                
                weight +=  nums[i];

            }
        }
        return days ;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        int ans = INT_MAX ;

        while(low <=high){
            int mid = (low+high) /2 ;

            if(numberOfDays(weights, mid)<=days){
                ans = mid ;
                high = mid -1 ;
            }
            else{
                low = mid +1 ;
            }
            
            
        }
        return ans ;

    }
};