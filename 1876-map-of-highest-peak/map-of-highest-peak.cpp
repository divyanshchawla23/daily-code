class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> heights(n,vector<int>(m,-1));

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(isWater[i][j]==1){
                    heights[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }

        int drow[4]= {-1,0,1,0};
        int dcol[4]= {0,1,0,-1};

        int ans = -1;

        while(!q.empty()){
            auto it = q.front();
            int row = it.first.first;
            int col = it.first.second;
            int steps = it.second;
            ans = max(ans,steps);
            q.pop();

            for(int i =0;i<4;i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if(nrow>=0 && nrow<n && ncol >=0 && ncol<m && heights[nrow][ncol]==-1){
                    heights[nrow][ncol]=steps+1;
                    q.push({{nrow,ncol},steps+1});
                }
            }
        }

        return heights;
    }
};