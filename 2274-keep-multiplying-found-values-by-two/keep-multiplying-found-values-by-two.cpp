class Solution {
public:
    bool bs(vector<int> &nums, int &orignal){
        int n  = nums.size();
        int l =0;
        int r = n-1;

        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==orignal) return true;
            else if(nums[mid]<orignal) l = mid+1;
            else r = mid-1;
        }

        return false;
        
    }
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        while(bs(nums,original)){
            original = original*2;
        }
        return original;
    }
};