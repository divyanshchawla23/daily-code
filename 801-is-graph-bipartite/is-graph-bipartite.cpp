class Solution
{
private:
    bool dfs(int node,int c, vector<vector<int>> &adj, vector<int> &col)
    {

        col[node] = c;
        
        for(auto it : adj[node]){

            if(col[it]==-1){
                if(dfs(it,!col[node],adj,col)==false) return false;
            }
            else if(col[it]==col[node]){
                return false;
            }
            
        }
        return true;


    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
            {
                adj[i].push_back(it);
            }
        }
        vector<int> col(n, -1);

        for (int i = 0; i < n; i++)
        {
            if (col[i] == -1)
            {
                if (dfs(i,1, adj, col) == false)
                    return false;
            }
        }

        return true;
    }
};