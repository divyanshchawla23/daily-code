class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        map<vector<int>, int> mpp;

        for (int i = 0; i < n; i++) {
            vector<int> row;
            for (int j = 0; j < m; j++) {
                row.push_back(grid[i][j]);
            }
            mpp[row]++;
        }

        for (int j = 0; j < m; j++) {
            vector<int> col;
            for (int i = 0; i < n; i++) {
                col.push_back(grid[i][j]);
            }
            if(mpp.find(col)!=mpp.end()){
                cnt+=mpp[col];
            }
        }

        return cnt;
    }
};