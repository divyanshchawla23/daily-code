class Solution {
public:

    bool possible(vector<int>& nums,int mid, int m, int k){

        int cnt =0;
        int numberB=0;

        for(int i =0;i<nums.size();i++){
            if (nums[i]<=mid){
                cnt = cnt +1;
            }
            else {
               numberB+= (cnt/k);
               cnt = 0; 
            }
        }
        numberB+= (cnt/k);

        if(numberB>=m) return true;
        else{return false;}

    }

    int minDays(vector<int>& nums, int m, int k) {
        long long val = m *1LL * k * 1LL;
        if(val>nums.size()) return -1 ;

        

        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;

        while(low<=high){
            int mid = low + (high-low)/2;

            if (possible(nums, mid,  m,  k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid +1 ;
            }
        }

        return ans ;

        
        
    }
};