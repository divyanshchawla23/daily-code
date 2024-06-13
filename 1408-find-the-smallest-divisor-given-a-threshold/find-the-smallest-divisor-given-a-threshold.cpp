class Solution {
public:
    int func(vector<int>& nums, int mid){
        int sum =0;
        for (int i =0;i<nums.size();i++){
            sum += ceil((double)nums[i]/(double)mid );
        }
        return sum ;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());

        int ans = -1 ;

        while(low<=high){

            int mid = low +(high-low)/2;

            if (func(nums,mid)<=threshold){
                ans = mid ;
                high = mid -1 ;
            }
            else{
                low = mid +1 ;

            }


        }
        return ans;
    }
};