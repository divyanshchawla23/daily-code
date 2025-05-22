class DisjointSet{

    public:
    
    vector<int> size,parent;

    DisjointSet(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i =0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUltParent(int u){
        if(parent[u]==u){
            return u;
        }

        return parent[u]= findUltParent(parent[u]);
    }

    void unionbySize(int u, int v){

        int ult_u = findUltParent(u);
        int ult_v = findUltParent(v);

        if(ult_u==ult_v){
            return;
        }

        if(size[ult_u]<size[ult_v]){
            size[ult_v]+=size[ult_u];
            parent[ult_u] = ult_v;
        }else{
            size[ult_u]+=size[ult_v];
            parent[ult_v] = ult_u;
        }

    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);

        int cntC = 0;
        int extraE = 0;

        for(auto it: connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUltParent(u)==ds.findUltParent(v)){
                extraE++;
            }else{
                ds.unionbySize(u,v);
            }

        }

        for(int i =0;i<n;i++){
            if(ds.parent[i]==i){
                cntC++;
            }
        }

        int ans = cntC - 1;

        if(ans<=extraE){
            return ans;
        }else return -1;

        
    }
};