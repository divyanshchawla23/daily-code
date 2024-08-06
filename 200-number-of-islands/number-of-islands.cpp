class Solution {
    int delR[4]={-1,0,1,0}; 
    int delC[4]={0,+1,0,-1};
private:
    void bfs(int row , int col,vector<vector<int>> &vis,vector<vector<char>> &grid){
        int n = grid.size();
        int m =grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty()){
            int Nrow = q.front().first;
            int Ncol = q.front().second;
            q.pop();
            for(int i =0;i<4;i++){
                int newR= Nrow + delR[i];
                int newC= Ncol + delC[i];

                if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]=='1' && !vis[newR][newC]){
                    vis[newR][newC]= 1;
                    q.push({newR,newC});
                } 
            }
            
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt =0;

        int n = grid.size();
        int m =grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if( grid[i][j]=='1' && !vis[i][j]){
                    bfs(i,j,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};