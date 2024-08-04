class Solution {

private:
    void dfs(int node, vector<int> adjLs[], vector<int> &vis) {
        // mark the more as visited
        vis[node] = 1; 
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& nums) {
        int n = nums[0].size();
         vector<int> adjLs[n]; 
        
        // to change adjacency matrix to list 
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                // self nodes are not considered
                if(nums[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        vector<int> vis(n,0) ;
        int cnt = 0; 
        for(int i = 0;i<n;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                cnt++;
               dfs(i, adjLs, vis); 
            }
        }
        return cnt; 
    }
};