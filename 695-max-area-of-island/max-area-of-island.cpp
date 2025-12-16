class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid,int n,int m,int drow[],int dcol[]){
        //vis[i][j]=1;
        grid[i][j]= 0;

        int size = 1;

        for(int ind = 0;ind<4;ind++){
            int nrow = i + drow[ind];
            int ncol = j + dcol[ind];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(grid[nrow][ncol]==1){
                    size += dfs(nrow,ncol,grid,n,m,drow,dcol);
                }
            }
        }

        return size;    
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        //vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1){
                    int size = dfs(i,j,grid,n,m,drow,dcol);
                    maxi = max(maxi,size);
                }
            }
        }
        return maxi;
    }
};