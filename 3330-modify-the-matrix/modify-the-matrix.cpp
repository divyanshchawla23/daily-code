class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> maxEl;

        for (int j = 0; j < m; j++) {
            int maxi = INT_MIN;
            for (int i = 0; i < n; i++) {
                maxi = max(maxi, matrix[i][j]);
            }
            maxEl.push_back(maxi);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = maxEl[j];
                }
            }
        }
        for (int i = n-1; i >=0 ; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (matrix[i][j] == -1) {
                    matrix[i][j] = maxEl.back();
                    maxEl.pop_back();
                }
            }
        }

        return matrix;
    }
};