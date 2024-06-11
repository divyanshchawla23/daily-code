class Solution {
public:

    int binarySearch(vector<int>& nums, int start, int end , int target){

        while(start<=end){

            int mid =(start+end)/2;

            if(nums[mid]==target){
                return mid;
            }

            else if (target>=nums[mid]){
                start = mid +1;
            }

            else if (target<=nums[mid]){

                end = mid -1 ;

            }

        }
            return -1 ;

    }

    int minIndex(vector<int>& nums){
        int n = nums.size();
        int start = 0;
        int end = n-1;

        while(start<=end){

            int mid = (start+end)/2;

            int next =(mid+1)%n; 
            int prev =(mid+n-1)%n;

            if (nums[start]<=nums[end]){
                return start;
            }

            else if(nums[mid]<=nums[next] && nums[mid]<=nums[prev]){
                return mid;
            }

            else if(nums[start]<=nums[mid] ){
                start = mid +1;
            }
            
            else if(nums[mid]<=nums[end]){
                end = mid - 1;
            }

        }
        return -1;

    }
    int search(vector<int>& nums, int target) {

        int minindex1 = minIndex(nums);

        int ans1 = binarySearch(nums, 0, minindex1-1 , target);

        if(ans1 != -1){
            return ans1;
        }

        int ans2 = binarySearch( nums, minindex1, nums.size()-1 , target);

        
        if(ans2 != -1){
            return ans2;
        }


        return -1 ;

    
    }
};