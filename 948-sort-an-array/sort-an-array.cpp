class Solution {
public:
    void sorting(vector<int>&nums,int low,int mid,int high){
        int left = low;
        int right = mid+1;

        vector<int> ans;

        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                ans.push_back(nums[left]);
                left++;
            }else{
                ans.push_back(nums[right]);
                right++;
            }
        } 

        while(left<=mid){
            ans.push_back(nums[left]);
            left++;
        }

        while(right<=high){
            ans.push_back(nums[right]);
            right++;
        }

        for(int i =low;i<=high;i++){
            nums[i]= ans[i-low];
        }
    }
    void helper(vector<int>&nums, int low , int high){
        if(low<high){
            int mid = (low+high)/2;
            helper(nums,low,mid);
            helper(nums,mid+1,high);
            sorting(nums,low,mid,high);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        helper(nums,low,high);
        return nums;
    }
};