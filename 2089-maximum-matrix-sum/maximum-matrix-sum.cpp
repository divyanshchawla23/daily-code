class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        long long total_sum = 0;
        int minus_count = 0;
        int smallest_number = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] < 0)
                    minus_count++;
                smallest_number = min(smallest_number, abs(matrix[i][j]));
                total_sum += abs(matrix[i][j]);
            }
        }

        if (minus_count % 2 == 0) {
            return total_sum;
        } else {
            return total_sum - (2 * smallest_number);
        }
    }
};