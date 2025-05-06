class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathvis,
             vector<vector<int>>& adj) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, vis, pathvis, adj))
                    return true;
            } else if (pathvis[it]) {
                return true;
            }
        }

        pathvis[node] = 0;
        return false;
    }

public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathvis, adj) == true)
                    return false;
            }
        }

        return true;
    }
};