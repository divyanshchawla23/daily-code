class Solution {
public:
    void dfs(int node, vector<vector<int>>& connections,
             vector<vector<int>>& adj, vector<int>& vis, int nodeId,
             vector<int>& nodeGroup) {

        vis[node] = 1;
        nodeGroup[node] = nodeId;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, connections, adj, vis, nodeId, nodeGroup);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1);
        vector<int> ans;
        vector<int> vis(c + 1, 0);
        vector<int> nodeGroup(c + 1);
        map<int, set<int>> mpp;

        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for (int i = 1; i <= c; i++) {
            if (!vis[i]) {
                int nodeId = i;
                dfs(i, connections, adj, vis, nodeId, nodeGroup);
            }
        }

        for (int i = 1; i <= c; i++) {
            int node = i;
            int nodeG = nodeGroup[i];
            mpp[nodeG].insert(node);
        }

        for (auto& it : queries) {
            int a = it[0];
            int nd = it[1];

            int groupOfQueryNode = nodeGroup[nd];

            if (a == 1) {
                if (mpp[groupOfQueryNode].find(nd) !=
                    mpp[groupOfQueryNode].end()) {
                    ans.push_back(nd);
                } else {
                    if (mpp[groupOfQueryNode].empty()) {
                        ans.push_back(-1);
                    } else {
                        ans.push_back(*mpp[groupOfQueryNode].begin());
                    }
                }
            } else if (a == 2) {
                mpp[groupOfQueryNode].erase(nd);
            }
        }

        return ans;
    }
};