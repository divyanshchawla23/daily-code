class Solution {
private:
    vector<int> dijk(int src,int n,  vector<vector<pair<int,int>>>& adj) {

        vector<int> dis(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        dis[src]=0;

        pq.push({0,src});

        while(!pq.empty()){
            int node= pq.top().second;
            int d=pq.top().first;
            pq.pop();

            for(auto it:    adj[node]){
                if(d + it.second <dis[it.first]){
                    dis[it.first]=d+it.second;
                    pq.push({d+it.second,it.first});
                }
            }

        }
        return dis;

    }

public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }


        int neighbours = n + 1;
        int city = -1;

        for(int i =0;i<n;i++){

            vector<int> dist = dijk(i, n, adj);

            int cnt =0;
            for(int j =0;j<n;j++){ 
                if(dist[j]<=distanceThreshold){
                    cnt++;
                }
            }
            if (cnt <= neighbours) {
                neighbours = cnt;
                city = i;
            }

        }

        return city;
    }
};