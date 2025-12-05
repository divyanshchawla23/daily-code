class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        int total_sum = 0;

        for (auto it : nums) {
            total_sum += it;
        }
        int sum1 = 0;
        for (int i = 0; i < n - 1; i++) {
            sum1 += nums[i];

            int sum2 = total_sum - sum1;

            if ((sum1 - sum2) % 2 == 0) {
                cnt++;
            }
        }

        return cnt;
    }
};