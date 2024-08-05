class Solution {
private:
    bool dfs(int node , int col, vector<int> &color , vector<int> adj[]){
        color[node]=col;

        for(auto it : adj[node]){
            if(color[it]==-1){
                if(dfs(it,!col,color,adj)==false) return false;
            }
            else if(color[it]==col) return false;
        }
        return true ;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector <int> color(V,-1);

        //convert to adj

        vector <int > adj[V];
        for(int i =0;i<V;i++){
            for(int j =0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }

        //
        for(int i =0;i<V;i++){
            if(color[i]==-1){
                if(dfs(i,0,color,adj)==false) return false;
            }

        }
        return true;

    }
};