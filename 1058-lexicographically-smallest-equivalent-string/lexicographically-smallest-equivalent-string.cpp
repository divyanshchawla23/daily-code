class DSU{
    public:
    vector<int> parent;
    vector<int> size;

    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findUParent(int v){
        if(parent[v]==v) return v;

        return parent[v] = findUParent(parent[v]);
    }

    void unionBySize(int u, int v){
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv) return;

        // Always attach larger to smaller
        if (pu < pv) {
            parent[pv] = pu;
        } else {
            parent[pu] = pv;
        }
    } 

};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int i =0;
        int n = s1.size();
        DSU ds(25);

        while(i<n){
           ds.unionBySize(s1[i]-'a',s2[i]-'a');
           i++; 
        }

        string result = "";
        for (char ch : baseStr) {
            int smallest_equiv = ds.findUParent(ch - 'a');
            result += (smallest_equiv + 'a');
        }

        return result;

    
    }
};