class Solution {
public:
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,1,0,-1};
    void dfs(int sr, int sc, vector<vector<int>>& image,vector<vector<int>>& vis,int n, int m, int color, int org){
        vis[sr][sc]=1;
        image[sr][sc]=color;

        for(int i =0;i<4;i++){
            int nrow = sr + drow[i];
            int ncol = sc + dcol[i];

            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                if(!vis[nrow][ncol]&& image[nrow][ncol]==org){
                    dfs(nrow,ncol,image,vis,n,m,color,org);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int org = image[sr][sc];
        vector<vector<int>> vis(n,vector<int>(m,0));

        dfs(sr,sc,image,vis,n,m,color,org);

        return image;

    }
};