class Solution {
    int drow[4]={-1,0,1,0};
    int dcol[4]={0,1,0,-1};
private: 
    void dfs(int row, int col, vector<vector<int>>& vis,vector<vector<int>>& heights){
        int n = heights.size();
        int m = heights[0].size(); 
        vis[row][col]=1;

        for(int i =0;i<4;i++){
            int nrow = row+drow[i];
            int ncol = col+dcol[i];

            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m && vis[nrow][ncol]==0 && heights[nrow][ncol]>=heights[row][col]){
                dfs(nrow,ncol,vis,heights);
            }
        }
    }

    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> vis1(n,vector<int>(m,0));
        vector<vector<int>> vis2(n,vector<int>(m,0));

        for(int i =0;i<n;i++){
            dfs(i,0,vis1,heights);
        }
        for(int j =0;j<m;j++){
            dfs(0,j,vis1,heights);
        }

        for(int i =0;i<n;i++){
            dfs(i,m-1,vis2,heights);
        }
        for(int j =m-1;j>=0;j--){
            dfs(n-1,j,vis2,heights);
        }

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j]==1 && vis2[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};