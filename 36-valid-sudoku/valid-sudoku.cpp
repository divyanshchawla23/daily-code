class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            set<char> st;
            for(int j=0; j<9; j++){
                char c = board[i][j];
                if(c=='.') continue;
                if(st.find(c)!=st.end()) return false;
                st.insert(c);
            }
        }

        // check columns
        for(int i=0; i<9; i++){
            set<char> st;
            for(int j=0; j<9; j++){
                char c = board[j][i];
                if(c=='.') continue;
                if(st.find(c)!=st.end()) return false;
                st.insert(c);
            }
        }

        for(int blockRow=0; blockRow<9; blockRow+=3){
            for(int blockCol=0; blockCol<9; blockCol+=3){
                set<char> st;
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        char c = board[blockRow+i][blockCol+j];
                        if(c=='.') continue;
                        if(st.find(c)!=st.end()) return false;
                        st.insert(c);
                    }
                }
            }
        }

        return true;
    }
};