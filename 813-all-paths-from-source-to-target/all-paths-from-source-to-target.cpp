class Solution {
public:
    void dfs(int node,vector<vector<int>>& graph,vector<int>&temp,vector<int>&vis,vector<vector<int>>& ans ){


        vis[node] =1;
        temp.push_back(node);
        if(node == (graph.size())-1){
            ans.push_back(temp);

        }

        for(auto it: graph[node]){
            if(!vis[it]){
                dfs(it,graph,temp,vis,ans);
            }
        }

        temp.pop_back();
        vis[node]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> ans;
        vector<int>vis(graph.size(),0);
        vector<int> temp;

        dfs(0,graph,temp,vis, ans);

        return ans;

    }
};