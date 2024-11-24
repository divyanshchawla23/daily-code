class Solution {
private:
    bool isEven(int n){
        if(n%2==0) return true;
        else return false;
    }
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int left =0;
        int right =0;

        while(right<n){
            if(isEven(nums[right])){
                swap(nums[left],nums[right]);
                left++;
            }
            right++;
        }

        return nums;

    }
};