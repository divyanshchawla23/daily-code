class Solution {
private:
    bool helper(int i, int j, int ind, vector<vector<char>>& board, int n,
                int m, string &word, int drow[], int dcol[]) {
        if (ind == word.size())
            return true;

        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == '*' ||
            board[i][j] != word[ind]) {
            return false;
        }

        char c = board[i][j];
        board[i][j] = '*';

        for (int d = 0; d < 4; d++) {
            int nrow = i + drow[d];
            int ncol = j + dcol[d];
            if (helper(nrow, ncol, ind + 1, board, n, m, word, drow, dcol))
                return true;
        }

        board[i][j] = c;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] &&
                    helper(i, j, 0, board, n, m, word, drow, dcol))
                    return true;
            }
        }
        return false;
    }
};