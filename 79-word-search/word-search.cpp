class Solution {
public:
    bool help(vector<vector<char>>& board, string word, int n, int m, int i,
              int j, int k) {

        if (k >= word.size()) {
            return true;
        }
        

        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '.' ||
            word[k] != board[i][j])
            return false;

        char temp =board[i][j];
        board[i][j]='.';

        int di[] = {+1,0,0,-1};
        int dj[] = {0,-1,1,0};
        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];
            if(help(board,  word,  n,  m,  nexti,nextj,  k+1)) return true;

        }

        board[i][j]=temp;
        return false;

    }


    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        

            for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0] && help(board, word, n, m, i, j, 0)) {
                    
                    return true ;
                }
            }
        }
        return false;
    }
};