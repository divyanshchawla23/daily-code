class DisjointSet
{

    vector<int> size;
    vector<int> parent;

public:
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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        int n = accounts.size();
        DisjointSet ds(n);
        map<string,int> mpp;
        for(int i =0;i<n;i++){
            for(int j =1;j<accounts[i].size();j++){
                if(mpp.find(accounts[i][j])==mpp.end()){
                    mpp[accounts[i][j]]= i;
                }else{
                    ds.unionbySize(i,mpp[accounts[i][j]]);
                }
            }
        }

        vector<vector<string>> merged(n);


        for(auto it: mpp){
            string str = it.first;
            int lvl = ds.findUltimateParent(it.second);

            merged[lvl].push_back(str);
        }


        vector<vector<string>> ans;

        for(int i =0;i<n;i++){
            if(merged[i].size()==0) continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(int j = 0;j<merged[i].size();j++){
                temp.push_back(merged[i][j]);
            }
            ans.push_back(temp);
        }


        return ans;
    }
};