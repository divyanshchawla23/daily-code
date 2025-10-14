class Solution {
public:
    bool isIncreasing(vector<int>& nums, int start, int end) {
        for(int i =start+1;i<=end;i++){
            if(nums[i]<=nums[i-1]){
                return false;
            }
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i + 2 * k - 1 < n; i++) {
            bool first = isIncreasing(nums, i, (i + k) - 1);
            bool second = isIncreasing(nums, i + k, (i + k + k) - 1);
            if (first && second)
                return true;
        }

        return false;
    }
};