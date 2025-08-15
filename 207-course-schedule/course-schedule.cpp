class Solution {
public:
    bool topoSort(int node, vector<int>& vis, vector<int>& pathvis, vector<vector<int>>& adj,stack<int> &st) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (topoSort(neighbor, vis, pathvis, adj,st)) return true;
            } else if (pathvis[neighbor]) {
                // Back edge found → cycle
                return true;
            }
        }
        st.push(node);
        pathvis[node] = 0;  // backtrack
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        stack<int> st;
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }
        vector<int> topo;

        vector<int> vis(n, 0), pathvis(n, 0);

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                if (topoSort(i, vis, pathvis, adj,st)) {
                    return false; // cycle detected
                }
            }
        }

        while(!st.empty()){
            topo.push_back(st.top());
            st.pop();
        }

        return true; // no cycle → can finish all courses


    }
};