class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        for (auto& it : edges) {
            adj[it[1]].push_back({it[0], 2 * it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dis(n, INT_MAX);
        pq.push({0, 0});
        dis[0] = 0;
        int ans = INT_MIN;

        while (!pq.empty()) {

            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            if (d > dis[node])
                continue;

            for (auto it : adj[node]) {

                if (dis[node] + it.second < dis[it.first]) {
                    dis[it.first] = dis[node] + it.second;
                    pq.push({dis[it.first], it.first});
                }
            }
        }

        if (dis[n - 1] == INT_MAX)
            return -1;

        return dis[n - 1];
    }
};