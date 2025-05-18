class Solution {
private:
    void topoSort(int n,vector<vector<int>> &adj,vector<int>&topo){

        vector<int> inDegree(n);

        queue<int> q;

        for(auto adjacent: adj){
            for(auto it : adjacent){
                inDegree[it]++;
            }
        }

        for(int i =0;i<inDegree.size();i++){
            if(inDegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:adj[node]){

                inDegree[it]--;
                if(inDegree[it]==0) q.push(it);
            }
        }

    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> topo;

        topoSort(n,adj,topo);


        if(topo.size()==n)   return topo;
        else return {};
    }
};