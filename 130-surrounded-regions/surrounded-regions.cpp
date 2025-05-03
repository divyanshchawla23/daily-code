class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& vis,
             vector<vector<char>>& board, int drow[], int dcol[]) {
        vis[i][j] = 1;
        int n = board.size();
        int m = board[0].size();

        for (int k = 0; k < 4; k++) {
            int nrow = i + drow[k];
            int ncol = j + dcol[k];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !(vis[nrow][ncol]) && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board,drow,dcol);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));

        int drow[4]={-1,0,1,0};
        int dcol[4]={0,+1,0,-1};

        // first row

        for (int j = 0; j < m; j++) {
            if (vis[0][j] == 0 && board[0][j] == 'O') {
                dfs(0, j, vis, board,  drow,  dcol);
            }
        }

        // last row

        for (int j = 0; j < m; j++) {
            if (vis[n - 1][j] == 0 && board[n - 1][j] == 'O') {
                dfs(n - 1, j, vis, board,  drow,  dcol);
            }
        }

        // first col

        for (int i = 0; i < n; i++) {
            if (vis[i][0] == 0 && board[i][0] == 'O') {
                dfs(i, 0, vis, board,  drow,  dcol);
            }
        }

        // last col

        for (int i = 0; i < n; i++) {
            if (vis[i][m - 1] == 0 && board[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, board,  drow,  dcol);
            }
        }

        // changing all the O --> X

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};