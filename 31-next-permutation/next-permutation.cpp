class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int index = -1;

        for(int i =n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                index = i;
                break;
            }
        }

        if(index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        cout << index << "ind->" << nums[index];

        for(int i = n-1;i>=0;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        sort(nums.begin()+index+1,nums.end());

        // 1 2  5 4 3 
    }
};