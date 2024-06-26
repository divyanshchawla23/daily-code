class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = n-1;


        while(start<=end){

            int mid = (start+end)/2;

            int next =(mid+1)%n; 
            int prev =(mid+n-1)%n;

            if (nums[start]<=nums[end])
            {
                return nums[start];
            }

            if(nums[mid]<=nums[prev]&&nums[mid]<=nums[next]){
                return nums[mid];
                
            }

            if(nums[start]<=nums[mid]){
                start = mid +1;
                
                
        
            }
             if(nums[mid]<=nums[end]){
                end = mid -1;
                
            }
             
            
        
        }
        return -1 ;
    }
};