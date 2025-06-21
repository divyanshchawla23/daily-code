class Solution {
private:    
    bool dfs(int node,vector<vector<int>>& graph,vector<int>& col, int c){
        col[node] = c;

        for(auto it: graph[node]){
            if(col[it]==-1){
                if(dfs(it,graph,col,!col[node])==false) return false;
            }else if(col[it]==col[node]){
                return false;
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
                if(dfs(i,graph,col,0)==false) return false;
            }
        }
        return true;
    }
};