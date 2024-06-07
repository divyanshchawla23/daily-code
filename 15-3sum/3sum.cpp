class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;  // Declare the set to store unique triplets
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates
            }

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    st.insert(temp);  // Insert the triplet into the set
                    j++;
                    k--;
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());  // Convert the set to a vector
        return ans;
    }
};
