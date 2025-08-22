class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        int firstRow = n, lastRow = -1;
        int firstCol = m, lastCol = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    firstRow = min(firstRow, i);
                    lastRow = max(lastRow, i);
                    firstCol = min(firstCol, j);
                    lastCol = max(lastCol, j);
                }
            }
        }

        return (lastRow - firstRow + 1) * (lastCol - firstCol + 1);
    }
};