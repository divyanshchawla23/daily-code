class Solution {
private:
    void dfs(int node,int parent,vector<int>&vis,vector<vector<int>>&adj,
    vector<int>&tm,vector<int>&lowtm,vector<vector<int>>&ans, int timer){

        vis[node]=1;
        tm[node]=lowtm[node]=timer;
        timer++;

        for(auto it:adj[node]){
            if(it==parent) continue;
            else if(!vis[it]){
                dfs(it,node,vis,adj,tm,lowtm,ans,timer);
                lowtm[node]=min(lowtm[node],lowtm[it]);
                //can this be critical edge
                if(lowtm[it]>tm[node]){
                    ans.push_back({it,node});
                }
            }
            else{
                lowtm[node]=min(lowtm[node],lowtm[it]);
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {

        static int timer = 1;
        vector<vector<int>> ans;
        vector<int> tm(n);
        vector<int> lowtm(n);
        vector<int> vis(n);
        // int timer = 1;
        vector<vector<int>> adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        dfs(0,-1,vis,adj,tm,lowtm,ans,timer);
        return ans;
    }
};