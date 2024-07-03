class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left =0;
        int right =0;
        int maxlen =0;
        int zeros =0;


        while (right<n){
            if(nums[right]==0) zeros++;

            if (zeros>k){
                if(nums[left]==0) zeros--;
                left++;
            }

            if(zeros<=k) maxlen = max(maxlen , right - left +1);

            right ++;
        }
        return maxlen;
    }
};