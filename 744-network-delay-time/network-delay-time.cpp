class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,int>    >pq;
        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int node = pq.front().second;
            int time = pq.front().first;
            pq.pop();

            

            for(auto it: adj[node]){
                if(time+it.second<dis[it.first]){
                    dis[it.first]= time+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }

        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dis[i] == INT_MAX) return -1;
            ans = max(ans, dis[i]);
        }

        return ans;
    }
};