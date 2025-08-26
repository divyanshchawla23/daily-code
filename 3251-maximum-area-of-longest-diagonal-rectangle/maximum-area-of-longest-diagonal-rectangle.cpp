class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int maxDiag = 0;

        for(auto & it: dimensions){
            int l = it[0];
            int b = it[1];

            int diag = l*l + b*b;
            int area = l*b;

            if(diag>maxDiag){
                maxDiag = diag;
                maxArea = area;
            }else if(diag == maxDiag){
                maxArea = max(area,maxArea);
            }
        }
        return maxArea;
    }
};