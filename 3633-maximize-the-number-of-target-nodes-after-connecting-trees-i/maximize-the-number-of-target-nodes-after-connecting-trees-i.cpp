class Solution {
private:
    int dfs(int src,vector<vector<int>>&adj,int k,vector<int>&vis){

        if(k<0) return 0 ;
        int cnt = 1;
        vis[src]=1;

        for(auto it:adj[src]){
            if(!vis[it]){
                cnt += dfs(it,adj,k-1,vis);
            }
        }
        return cnt;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n1 = edges1.size();
        int n2 = edges2.size();
        vector<vector<int>> adj1(n1+1);
        vector<vector<int>> adj2(n2+1);
        for(auto it:edges1){
           adj1[it[0]].push_back(it[1]); 
           adj1[it[1]].push_back(it[0]); 
        }
        for(auto it:edges2){
           adj2[it[0]].push_back(it[1]); 
           adj2[it[1]].push_back(it[0]); 
        }

        vector<int> dis1(n1+1,-1);
        
        for(int i =0;i<=n1;i++){  
            vector<int>vis(n1+1,0);         
            dis1[i] = dfs(i,adj1,k,vis);
        }

        vector<int> dis2(n2+1,-1);
        
        for(int i =0;i<=n2;i++){ 
            vector<int>vis(n2+1,0);       
            dis2[i] = dfs(i,adj2,k-1,vis);          
        }

        int maxCntInDist2 = *max_element(dis2.begin(),dis2.end());

        for(auto &it: dis1){
            it+=maxCntInDist2;
        }

        return dis1;

    }
};