class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it :flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        // {stops,{node,dis}}
        queue<pair<int,pair<int,int>>>q;

        vector<int> dis(n,INT_MAX);

        q.push({0,{src,0}});

        while(!q.empty()){
            int stop = q.front().first;
            int node = q.front().second.first;
            int dist = q.front().second.second;
            q.pop();

            if(stop>k) break;

            for(auto it: adj[node]){
                if(dist+it.second<dis[it.first] && stop <=k){
                    dis[it.first]=dist+it.second;
                    q.push({stop+1,{it.first,dist+it.second}});
                }
            }
        }



        if(dis[dst]==INT_MAX) return -1;
        return dis[dst];






    }
};