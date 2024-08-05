class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue< pair< pair<int,int>,int >  > q ;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector <int>> ans = grid;;

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(ans[i][j]==2)
                q.push({{i,j},0});
            }
        }

        int time =0;

        while(!q.empty()){
            int r =q.front().first.first;
            int c =q.front().first.second;
            int t =q.front().second;
            time = max(time , t);
            q.pop();
            int dRow[] = {-1,0,1,0};
            int dCol[] = {0,1,0,-1};

            for(int i =0;i<4;i++){
                int newR = r + dRow[i];
                int newC = c+ dCol[i];

                if(newR>=0 && newR<n && newC>=0 && newC<m && ans[newR][newC]!=2  && ans[newR][newC]==1){
                    q.push( {{newR,newC},t+1} );
                    ans[newR][newC]= 2;
                }
            }

        }

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(ans[i][j]==1) return -1;
                
            }
        }

        return time;
    }
};