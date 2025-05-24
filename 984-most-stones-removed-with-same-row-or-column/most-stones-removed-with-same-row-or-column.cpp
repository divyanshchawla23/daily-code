class DSU {

    public:
    vector<int> size , parent;

    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i =0;i<=n;i++){
            parent[i]= i;
        }
    }

    int ultimateParent(int n){
        if(parent[n]==n){
            return n;
        }
        return parent[n]= ultimateParent(parent[n]);
    }

    void unionBySize(int u, int v){
        int ult_u = ultimateParent(u);
        int ult_v = ultimateParent(v);

        if(size[ult_u]<size[ult_v]){
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
    int removeStones(vector<vector<int>>& stones) {

        int n = stones.size();
        DSU ds(n);

        for(int i =0;i<stones.size();i++){
            for(int j = i+1;j<stones.size();j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    if(ds.ultimateParent(i)!=ds.ultimateParent(j)){
                        ds.unionBySize(i,j);
                    }
                }
            }
        }


        int ans = 0;
        for(int i =0;i<n;i++){
            if(ds.parent[i]==i){
                ans+=ds.size[i]-1;
            }
        }

        return ans;

    }
};