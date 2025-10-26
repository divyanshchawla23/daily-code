class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis,
             int n, int m, int drow[], int dcol[]) {
        vis[i][j] = 1;

        for (int ind = 0; ind < 4; ind++) {
            int nrow = i + drow[ind];
            int ncol = j + dcol[ind];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                if (grid[nrow][ncol] == 1 && !vis[nrow][ncol]) {
                    dfs(nrow, ncol, grid, vis, n, m, drow, dcol);
                }
            }
        }
    }
    int findNumberofIslands(vector<vector<int>>& grid) {
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, grid, vis, n, m, drow, dcol);
                    islands++;
                }
            }
        }

        return islands;
    }
    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = findNumberofIslands(grid);
        cout << islands;
        if (islands > 1 || islands == 0) {
            return 0;
        } else { // island is 1 and go one and convert and check
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == 1) {
                        grid[i][j] = 0;
                        int abc = findNumberofIslands(grid);
                        if (abc > 1 || abc == 0) {
                            return 1;
                        }
                        grid[i][j] = 1;
                    }
                    
                }
            }
        }
        return 2;
    }
};