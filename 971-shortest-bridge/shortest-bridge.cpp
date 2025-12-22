class Solution {
public:
    int n;
    int m;
    typedef pair<pair<int, int>, int> P;
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis,queue<P>& q, int drow[], int dcol[]) {
        vis[i][j]=1;
        q.push({{i,j},0});

        for(int ind =0;ind<4;ind++){
            int nrow = i + drow[ind];
            int ncol = j + dcol[ind];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    dfs(nrow,ncol,grid,vis,q,drow,dcol);
                }
            }
        }
    }
    int bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, queue<P>& q , int drow[], int dcol[]){

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int level = q.front().second;
            q.pop();

            for(int ind =0;ind<4;ind++){
                int nrow = r + drow[ind];
                int ncol = c + dcol[ind];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    if(grid[nrow][ncol] == 0 && !vis[nrow][ncol]){
                        q.push({{nrow,ncol},level+1});
                        vis[nrow][ncol]=1;
                    }
                    else if(grid[nrow][ncol] == 1 && !vis[nrow][ncol]){
                        return level;
                    }
                }
            }

        }
        return -1;

    }
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<P> q; // {{row,col},level}
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, grid, vis, q , drow, dcol);
                    return bfs(grid, vis, q , drow, dcol);
                }
            }
        }
        return -1;
    }
};