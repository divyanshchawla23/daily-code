class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int a = k;

        for(auto & it: nums){
            a^=it;
        }

        return __builtin_popcount(a);
    }
};