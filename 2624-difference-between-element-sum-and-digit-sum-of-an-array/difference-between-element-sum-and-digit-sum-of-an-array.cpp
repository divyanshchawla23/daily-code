class Solution {
public:
    int sumUtil(int n){
        int sum = 0;
        while(n){
            int lastDigit = n % 10;
            sum += lastDigit;
            n = n/10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int totalSum = 0;
        for(auto &it: nums){
            totalSum += it;
        }
        int digitSum = 0;
        for(auto &it: nums){
            int digiSum = sumUtil(it);
            digitSum += digiSum;
        }
        return totalSum - digitSum;
    }
};