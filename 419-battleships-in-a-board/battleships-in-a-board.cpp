class Solution {
public:
    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<char>>& board,
             vector<vector<int>>& vis, int n, int m) {

        vis[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                if (!vis[nrow][ncol] && board[nrow][ncol] == 'X') {
                    dfs(nrow, ncol, board, vis, n, m);
                }
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'X') {
                    dfs(i, j, board, vis, n, m);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};