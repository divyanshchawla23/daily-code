class Solution {
private:
    void dfs(int sr, int sc,vector<vector<int>>& vis,
        vector<vector<int>>& image,int n, int m, int orginalColor,int drow[],int dcol[], int color,
        vector<vector<int>> &ans)
    {   
        ans[sr][sc]=color;

        for(int i =0;i<4;i++){
            int nrow = sr + drow[i];
            int ncol = sc+ dcol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                if(ans[nrow][ncol]==orginalColor && ans[nrow][ncol]!=color){
                    dfs(nrow,ncol,vis,image,n,m,orginalColor,drow,dcol,color,ans);
                }
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int orginalColor = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<vector<int>> vis(n,vector<int> (m,0));

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        dfs(sr,sc,vis,image,n,m,orginalColor,drow,dcol,color,ans);

        return ans;
    }
};