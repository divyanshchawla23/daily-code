class Solution {
public:
    int dfs(int node, int parent, vector<vector<int>>& adj,vector<int>& values,int k, int &cnt){
        int sum = values[node];

        for(auto it: adj[node]){

            if(it!=parent){

                sum+=dfs(it,node,adj,values,k,cnt);
                

            }

        }

        sum = sum%k;
        if(sum==0) cnt++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        for(auto &it: edges){
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        int sum = 0;

        dfs(0,-1,adj,values,k,cnt);


        return cnt;
    }
};