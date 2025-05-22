class Solution {
    int mod  = 1e9+7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> adj(n);

        // [] -> {node,dis}
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<long long> dis(n,LLONG_MAX);
        vector<int> ways(n,0);

        dis[0]= 0;
        ways[0]= 1;


        // {dis,node}
        priority_queue< pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>    >   pq;

        pq.push({0,0});

        while(!pq.empty()){
            long long node= pq.top().second;
            long long d = pq.top().first;
            pq.pop();

            for(auto it: adj[node]){
                long long sum = (d+ it.second);
                if(sum<dis[it.first]){
                    dis[it.first]= sum;
                    pq.push({sum,it.first});
                    ways[it.first] = ways[node];
                }
                else if(sum ==dis[it.first]){
                   
                    ways[it.first] = (ways[it.first] + ways[node]) % mod;
                }
            }
        }

        return (ways[n-1] % mod);


    }
};