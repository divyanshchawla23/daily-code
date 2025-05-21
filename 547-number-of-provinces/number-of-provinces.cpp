class DisjointSet{
    vector<int> size,parent;

    public:

        DisjointSet(int n){
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i =0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findUlt(int n){
            if(parent[n]==n){
                return n;
            }
            return parent[n]=findUlt(parent[n]);
        }

        void unionBySize(int u , int v){

            int ult_u = findUlt(u); 
            int ult_v = findUlt(v); 

            if(ult_u==ult_v) return;

            if(ult_u<ult_v){
                size[ult_v]+=size[ult_u];
                parent[ult_u]=ult_v;
            }else{
                size[ult_u]+=size[ult_v];
                parent[ult_v]=ult_u;
            }

        }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        DisjointSet ds(n);
        vector<vector<int>> edges;
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }

        int cnt =0;

        for(int i =0;i<n;i++){
            if(ds.findUlt(i)==i){
                cnt++;
            }
        }
        return cnt;
    }
};