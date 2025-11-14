class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> result(n,vector<int>(n,0));

        for(int k = 0; k < queries.size(); k++){
            int row1 = queries[k][0];
            int row2 = queries[k][2];
            int col1 = queries[k][1];
            int col2 = queries[k][3];
            for(int i = row1; i <= row2; i++){
                for(int j = col1; j <= col2; j++){
                    result[i][j]++;
                }
            }
        }
        return result;
    }
};