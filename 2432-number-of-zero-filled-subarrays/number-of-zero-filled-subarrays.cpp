class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long curr = 0;
        long long ans =0;
        for(auto it:nums){
            if(it==0){
                curr++;
                ans+=curr;
            }
            else{
                curr = 0;
            }
        }
        return ans;
    }
};