class Solution {
private:
    void bfs(int row, int col, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int drow[], int dcol[]) {
                
                int n = grid.size();
                int m = grid[0].size();
                
                queue<pair<int,int>> q;

                q.push({row,col});
                vis[row][col]=1;

                while(!q.empty()){
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();

                    for(int i =0;i<4;i++){
                        int nrow = row + drow[i];
                        int ncol = col + dcol[i];

                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                        && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                            q.push({nrow,ncol});
                             vis[nrow][ncol] = 1;
                        }
                    }
                }


             }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // check all the boundries;

        // first row;

        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && vis[0][i] == 0) {
                bfs(0, i, grid, vis, drow, dcol);
            }
        }

        // last row;

        for (int i = 0; i < m; i++) {
            if (grid[n - 1][i] == 1 && vis[n - 1][i] == 0) {
                bfs(n - 1, i, grid, vis, drow, dcol);
            }
        }

        // first col;

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && vis[i][0] == 0) {
                bfs(i, 0, grid, vis, drow, dcol);
            }
        }

        // last col;

        for (int i = 0; i < n; i++) {
            if (grid[i][m - 1] == 1 && vis[i][m - 1] == 0) {
                bfs(i, m - 1, grid, vis, drow, dcol);
            }
        }

        // check if there is 1 who is not vis add it to cnt;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};