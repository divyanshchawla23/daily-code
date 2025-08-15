class Solution {
public:
    bool cycle(int node, vector<int> &vis,vector<int> &pvis,vector<vector<int>> &adj){
        vis[node]=1;
        pvis[node]=1;

        for(auto it: adj[node]){
            if(!vis[it]){
               if(cycle(it,vis,pvis,adj)) return true;
            }else if(pvis[it]){
                return true;
            }
        }

        pvis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;

        vector<vector<int>> adj(n);

        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        vector<int> pvis(n,0);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(cycle(i,vis,pvis,adj)) return false;
            }
        }

        return true;


    }
};