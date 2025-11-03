class Solution {
public:
    void markingUtil(int r, int c, vector<vector<int>> &grid, int n , int m){
        //UP
        for(int i=r-1;i>=0;i--){
            if(grid[i][c]==2 || grid[i][c]==3){
                break;
            }
            grid[i][c]=1;
        }
        //right
        for(int i=c+1;i<n;i++){
            if(grid[r][i]==2 || grid[r][i]==3){
                break;
            }
            grid[r][i]=1;
        }
        //down
        for(int i=r+1;i<m;i++){
            if(grid[i][c]==2 || grid[i][c]==3){
                break;
            }
            grid[i][c]=1;
        }
        //left
        for(int i=c-1;i>=0;i--){
            if(grid[r][i]==2 || grid[r][i]==3){
                break;
            }
            grid[r][i]=1;
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        int cnt = 0;
        // 0 -> unvisited;
        // 1 -> visited;
        // 2 -> guard;
        // 3 -> wall;
        for(auto &it: guards){
            int r = it[0];
            int c = it[1];
            grid[r][c]=2;
        }
        for(auto &it: walls){
            int r = it[0];
            int c = it[1];
            grid[r][c]=3;
        }

        for(auto &it: guards){
            int r = it[0];
            int c = it[1];
            markingUtil(r,c,grid,n,m);
        }

        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};