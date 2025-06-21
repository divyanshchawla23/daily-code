class Solution {
private:    
    bool bfs(int node,vector<vector<int>>& graph,vector<int>& col, int c){
        queue<int> q;
        col[node] = c;
        q.push(node);
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it: graph[node]){
                if(col[it]==-1){
                    col[it]=!col[node];
                    q.push(it);
                }else if(col[it]==col[node]){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);

        for(int i =0;i<n;i++){
            if (col[i] == -1) {
                if(bfs(i,graph,col,0)==false) return false;
            }
        }
        return true;
    }
};