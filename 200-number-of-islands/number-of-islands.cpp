class Solution {
private:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis , int drow[], int dcol[] ){
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j]= 1;

        for(int ind =0;ind<4;ind++){
            int nrow = i + drow[ind];
            int ncol = j + dcol[ind];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol <m && vis[nrow][ncol]==0 && grid[nrow][ncol]== '1'){
                dfs(nrow,ncol,grid,vis,drow,dcol);
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt =0;
        int n = grid.size();
        int m = grid[0].size();

        int drow[4]= {-1,0,1,0};
        int dcol[4]= {0,1,0,-1};

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]== '1' && vis[i][j]==0){
                    dfs(i,j,grid,vis, drow, dcol);
                    cnt++;
                }
            }
        }
        


        return cnt;
    }
};