class Solution {
public:
    bool checkCycle(int node, int parent, vector<vector<int>>& nums,
                    vector<vector<int>>& adj, vector<int>& vis,
                    vector<int>& pvis,vector<int>&topo,stack<int>& st) {

        vis[node] = 1;
        pvis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (checkCycle(it, node, nums, adj, vis, pvis,topo,st))
                    return true;
            } else if (pvis[it]) {
                return true;
            }
        }
        st.push(node);
        pvis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites,vector<int>&topo,stack<int>&st) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        for (auto& it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> pvis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (checkCycle(i, -1, prerequisites, adj, vis, pvis,topo,st))
                    return false;
            }
        }
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        stack<int>st;
        vector<int> topo;
        bool ans = canFinish(numCourses,prerequisites,topo,st);
        while(!st.empty()){
            int node =st.top();
            st.pop();
            topo.push_back(node);
        }
        if(ans==false) return {};
        else return topo;
    }
};