class Solution {

private:
    void dfs(int row, int col, vector<vector<int>>& grid,vector<vector<int>>& vis, int drow[],int dcol[],int n , int m){

        vis[row][col]=1;

        for(int i =0;i<4;i++){
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(!vis[nrow][ncol] && grid[nrow][ncol]==1){
                    dfs(nrow,ncol,grid,vis,drow,dcol,n,m);
                }
            }
        }

    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,+1,0,-1};

        for(int i =0;i<n;i++){
            if(grid[i][0]==1 && !vis[i][0]) dfs(i,0,grid,vis,drow,dcol,n,m);
        }

        for(int i =0;i<n;i++){
            if(grid[i][m-1]==1 && !vis[i][m-1]) dfs(i,m-1,grid,vis,drow,dcol,n,m);
        }

        for(int j =0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]) dfs(0,j,grid,vis,drow,dcol,n,m);
        }

        for(int j =0;j<m;j++){
            if(grid[n-1][j]==1 && !vis[n-1][j]) dfs(n-1,j,grid,vis,drow,dcol,n,m);
        }

        int cnt = 0;

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};