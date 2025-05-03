class Solution {
private:
    bool bfs(int node ,vector<vector<int>>& adj, vector<int>&col){
        
        col[node] = 1;
        queue<int> q;
        q.push(node);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it : adj[node]){
                if(col[it]==-1){
                    col[it]  = !(col[node]);
                    q.push(it);
                }
                else if (col[node]==col[it]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for(int i =0;i<n;i++){
            for(auto it : graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<int> col(n,-1);
        

        for(int i =0;i<n;i++){
            if(col[i]==-1){
                if(bfs(i,adj,col)==false) return false;
            }
        }

        return true;
        

        

        

    }
};