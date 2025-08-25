class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ans(n, vector<int>(m, -1));

        map<int, vector<int>> mpp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                mpp[i - j].push_back(mat[i][j]);
            }
        }

        for (auto &it : mpp) {
            sort(it.second.begin(), it.second.end());
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                ans[i][j] = mpp[i-j].back();
                mpp[i-j].pop_back();
            }
        }

        return ans;
    }
};