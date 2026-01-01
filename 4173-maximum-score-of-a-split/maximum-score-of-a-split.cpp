class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long>prefixSum(n);
        vector<int>suffixSum(n);
        prefixSum[0]=nums[0];
        suffixSum[n-2] = nums[n-1];

        for(int i =1 ;i<n;i++){
            prefixSum[i]= prefixSum[i-1]+nums[i];
        }
    
        for(int i =n-3;i>=0;i--){
            suffixSum[i]= min(suffixSum[i+1],nums[i+1]);
        }
        

        long long ans = LLONG_MIN;

        for(int i =0;i<=n-2;i++){
            long long score  = prefixSum[i]-suffixSum[i];
            ans = max(ans, score);
        }

        return ans;

    }
};