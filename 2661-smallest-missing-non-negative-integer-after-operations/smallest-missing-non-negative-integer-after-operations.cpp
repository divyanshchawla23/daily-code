class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int ans = 0;
        map<int, int> mpp;

        for (auto& it : nums) {
            int r = -1;
            if(it<0){
                r = ((it % value) + value) % value;
            }
            else r = (it % value);

            mpp[r]++;
        }

        while (mpp[(ans % value)] > 0) {
            mpp[(ans % value)]--;
            ans++;
        }

        return ans;
    }
};