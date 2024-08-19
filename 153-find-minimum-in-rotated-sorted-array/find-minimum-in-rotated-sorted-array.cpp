class Solution {
private:

    int solve(vector<int> nums){
        int n  = nums.size();
        int low =0;
        int high  = n-1;

        while(low<=high){
            int mid = (low + high) / 2;
            int next = (mid+1)%n; 
            int prev = (mid+n-1)%n; 

            if(nums[low]<=nums[high]) return nums[low];

            else if(nums[mid]<=nums[next] && nums[mid]<=nums[prev]) return nums[mid];

            else if (nums[low]<=nums[mid]) low = mid+1;
            
            else if (nums[mid]<=nums[high]) high = mid-1;
        }

        return -1;
    }

public:
    int findMin(vector<int>& nums) {
        int x = solve(nums);
        return x;

    }
};