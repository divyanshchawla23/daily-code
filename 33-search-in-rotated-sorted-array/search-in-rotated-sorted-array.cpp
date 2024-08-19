class Solution {
private:
    int index(vector<int>& nums){
        int n = nums.size();
        int low =0;
        int high = n-1;

        while(low<=high){
            int mid = (low+high) /2;
            int next = (mid+1) %n;
            int prev = (mid+n-1) %n;

            if(nums[low]<=nums[high]) return low;

            else if(nums[mid]<=nums[prev] && nums[mid]<=nums[next]) return mid;

            else if(nums[low]<=nums[mid]) low = mid+1;
            
            else if(nums[mid]<=nums[high]) high = mid-1;
        }

        return -1;

    }

    int bs(vector<int> nums, int low, int high, int x){

        while(low<=high){
            int mid = (low + high) /2;

            if(nums[mid]==x) return mid;

            else if(nums[mid]>x) high = mid -1;

            else low = mid +1 ;
        }

        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        int minIndex = index(nums);
        int n = nums.size();

        int ans1 = bs(nums,0,minIndex-1,target);
        int ans2 = bs(nums,minIndex,n-1,target);

        if(ans1!=-1) return ans1;
        if(ans2!=-1) return ans2;


        return -1;

        
    }
};