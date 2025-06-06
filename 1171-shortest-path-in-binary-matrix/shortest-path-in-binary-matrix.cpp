class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();


        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
        //  {dist,{row,col}}
        queue<pair<pair<int, int>, int>> q;
        dis[0][0] = 0;
        q.push({{0, 0}, 0});

        int drow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dcol[8] = {0, 1, 1, 1, 0, -1, -1, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            if (r == n - 1 && c == n-1)
                return d +1 ;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 0 && d + 1 < dis[nrow][ncol]) {
                    dis[nrow][ncol] = 1 + d;
                    q.push({{nrow, ncol}, 1 + d});
                }
            }
        }

        return -1;
    }
};