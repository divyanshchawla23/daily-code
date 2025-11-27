class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int a = INT_MIN;
        int b = INT_MAX;
        int sumA = 0;
        int sumB = 0;

        for(auto it: nums){
            sumA += it;
            a = max(a,sumA);
            if(sumA<0) sumA = 0;
        }

        for(auto it: nums){
            sumB += it;
            b = min(b,sumB);
            if(sumB>0) sumB = 0;
        }

        return max(a,abs(b));
    }
};