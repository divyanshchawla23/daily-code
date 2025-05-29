class Solution {
private:
    void dfs(int node, int mark, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& marking) {

        
        marking[node] = mark;
        vis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, !marking[node], adj, vis, marking);
            }
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size();
        int m = edges2.size();

        vector<vector<int>> adj1(n + 1);
        vector<vector<int>> adj2(m + 1);

        for (auto it : edges1) {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }

        for (auto it : edges2) {
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        vector<int> marking1(n + 1, -1);
        vector<int> marking2(m + 1, -1);
        vector<int> targetNodes1(n + 1, 0);
        vector<int> targetNodes2(m + 1, 0);

        vector<int> vis1(n + 1, 0);
        vector<int> vis2(m + 1, 0);

        dfs(0, 0, adj1, vis1, marking1);
        dfs(0, 0, adj2, vis2, marking2);

        int cnt0_1 = 0, cnt1_1 = 0;
        for (int i = 0; i <= n; i++) {
            if (marking1[i] == 0) cnt0_1++;
            else if (marking1[i] == 1) cnt1_1++;
        }

        int cnt0_2 = 0, cnt1_2 = 0;
        for (int i = 0; i <= m; i++) {
            if (marking2[i] == 0) cnt0_2++;
            else if (marking2[i] == 1) cnt1_2++;
        }

        int maxCntFromDis2 = max(cnt0_2, cnt1_2);

        vector<int> ans (n+1);

        for(int i =0;i<=n;i++){
            int mark = marking1[i];
            if(mark ==0){
                ans[i] = cnt0_1 + maxCntFromDis2;
            }else{
                ans[i] = cnt1_1 + maxCntFromDis2;
            }
        }

        return ans;
    }
};