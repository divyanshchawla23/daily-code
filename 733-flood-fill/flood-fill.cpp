class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& ans, int newColor , int delRow[], int delCol[], int inColor){
        int n = ans.size();
        int m = ans[0].size();
        ans[sr][sc]= newColor;
        for(int i =0;i<4;i++){
            int row = sr + delRow[i];
            int col = sc + delCol[i];
            if(row>=0 && row<n && col >=0&&col<m && ans[row][col]== inColor && ans[row][col]!= newColor){
                dfs(row, col , ans , newColor , delRow , delCol , inColor);
            }
        }

    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int inColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int delRow[4]={-1,0,1,0};
        int delCol[4]={0,1,0,-1};
        dfs(sr,sc,ans,color,delRow,delCol,inColor);
        return ans;
    }
};