class Solution {
public:

    int cnt =0;

    void merge(vector<int> &nums, int left , int right, int mid){
        vector<int> temp;
        int i =left;
        int j =mid+1;

        while(i<=mid && j<=right){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid){            
            temp.push_back(nums[i]); 
            i++;  
        }

        while(j<=right){         
            temp.push_back(nums[j]);
            j++;                     
        }


        for(int i =left;i<=right;i++){
            nums[i]=temp[i-left]; 
        }
    }

    void count(vector<int>&nums, int left,int right , int mid){
        int r = mid+1;
        for(int i =left;i<=mid;i++){
            while(r<=right && nums[i]>(long long)2*nums[r]) r++;
            cnt+= r-(mid+1);
        }
    }

    void merge_sort(vector<int>& nums, int left, int right){
        if(left>=right) return ;
        int mid = (left+right) /2;
        merge_sort( nums,  left,  mid);
        merge_sort( nums,  mid+1,  right);
        count(nums,left,right,mid);
        merge(nums,left,right,mid);
        

    }

    int reversePairs(vector<int>& nums) {
        int n =nums.size();
        merge_sort(nums,0,n-1);
        return cnt;
    }
};