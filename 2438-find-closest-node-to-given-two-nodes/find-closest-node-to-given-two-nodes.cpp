class Solution {

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dis1(n, INT_MAX);
        vector<int> dis2(n, INT_MAX);
        dis1[node1] = 0;
        dis2[node2] = 0;
        vector<int> vis1(n, 0);
        vector<int> vis2(n, 0);
        //{node,dis}
        queue<pair<int, int>> q;

        // bfs(node1,edges,dis1,q);
        q.push({node1, 0});
        vis1[node1] = 1;
        while (!q.empty()) {
            int node = q.front().first;
            int ds = q.front().second;
            q.pop();

            
            int adjNode = edges[node];
            
            if (edges[node] != -1 && !vis1[adjNode]) {
                dis1[adjNode] = ds + 1;
                vis1[adjNode] = 1;
                q.push({adjNode, dis1[adjNode]});
            }
        }
        
        // bfs(node2medges,dis2,q);
        q.push({node2, 0});
        vis2[node2] = 1;
        while (!q.empty()) {
            int node = q.front().first;
            int ds = q.front().second;
            q.pop();

            int adjNode = edges[node];
            if (edges[node] != -1 && !vis2[adjNode]) {
                dis2[adjNode] = ds + 1;
                vis2[adjNode] = 1;
                q.push({adjNode, dis2[adjNode]});
            }
        }

        int ans = INT_MAX;
        int minDistanceIndex = -1;

        for (int i = 0; i < n; i++) {
            int d1 = dis1[i];
            int d2 = dis2[i];

            int maxOfd1d2 = max(d1, d2);

            if(ans>maxOfd1d2){
                ans = maxOfd1d2;
                minDistanceIndex = i;
            }
        }

        return minDistanceIndex;
    }
};