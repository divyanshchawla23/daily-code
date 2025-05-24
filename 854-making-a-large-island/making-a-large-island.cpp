class DisjointSet
{

public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimateParent(int v)
    {

        if (v == parent[v])
        {
            return v;
        }
        return parent[v] = findUltimateParent(parent[v]);
    }

    void unionbySize(int u, int v)
    {

        int ult_u = findUltimateParent(u);
        int ult_v = findUltimateParent(v);

        if (ult_u == ult_v)
        {
            return;
        }

        if (size[ult_u] < size[ult_v])
        {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else
        {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
private:
    bool isValid(int row, int col, int n){
        return row>=0 && row < n && col>=0 && col < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        DisjointSet ds(n*n);

        int maxSize = 0;

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,1,0,-1};

        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j]==1){
                    for(int ind = 0;ind<4;ind++){
                        int nrow = i + drow[ind];
                        int ncol = j + dcol[ind];
                        if(isValid(nrow,ncol,n) && grid[nrow][ncol]==1){
                            int nd = i * n + j;
                            int adjnd = nrow * n + ncol;
                            ds.unionbySize(nd,adjnd);
                        }
                    }
                }
            }
        }


        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                set<int> st;
                if(grid[i][j]==0){
                    for(int ind = 0;ind<4;ind++){
                        int nrow = i + drow[ind];
                        int ncol = j + dcol[ind];
                        if(isValid(nrow,ncol,n) && grid[nrow][ncol]==1){
                            int nd = nrow * n + ncol;
                            st.insert(ds.findUltimateParent(nd));
                        }
                    }
                    int sizeTotal = 0;
                    for(auto it: st){
                        sizeTotal+= ds.size[it];
                    }
                    maxSize = max(maxSize,sizeTotal+1);
                    
                }
            }
        }

        if(maxSize==0){
            return (n*n);
        }
        return maxSize;
    }
};