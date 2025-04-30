class Solution {
private:
void dfs(int node,vector<int>& vis, vector<vector<int>>& adj, int n) {

    vis[node]=1;

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,n);
        }
    }

    
}
public: 
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < isConnected.size(); i++) {
            for (int j = 0; j < isConnected[i].size(); j++) {
                if (isConnected[i][j] && i!=j) {
                    adj[i + 1].push_back(j + 1);
                    adj[j + 1].push_back(i + 1);
                }
            }
        }

        int cnt = 0;

        vector<int> vis(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            if(!vis[i]){
                dfs(i,vis, adj, n);
                cnt++;
            }
        }
        return cnt;
    }
};