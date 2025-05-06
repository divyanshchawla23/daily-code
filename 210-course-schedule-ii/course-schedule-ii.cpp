class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        vector<int> inD(n);
        vector<int> topo;

        queue<int> q;

        for(int i =0;i<n;i++){
            for(auto it : adj[i]){
                inD[it]++;
            }

        }
        for(int i =0;i<n;i++){
            if(inD[i]==0){
                q.push(i);
            }

        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it: adj[node]){
                inD[it]--;
                if(inD[it]==0){
                    q.push(it);
                }
            }
        }

        

        if(topo.size()==n)return topo;
        else return {};


    }
};