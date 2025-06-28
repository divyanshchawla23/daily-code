class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();

        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        auto comp = [](vector<int>& a, vector<int>& b) { 
            return a[0] > b[0]; 
        };
        auto comp1 = [](vector<int>& a, vector<int>& b) { 
            return a[1] < b[1]; 
        };

        sort(v.begin(), v.end(), comp);

        // ============================

        for (auto it : v) {
            cout << it[0] << it[1] << ",";
        }
        cout << endl;

        sort(v.begin(), v.begin() + k, comp1);

        for (auto it : v) {
            cout << it[0] << it[1] << ",";
        }

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i][0]);
        }
        return ans;
    }
};