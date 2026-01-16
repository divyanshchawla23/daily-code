class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int maxHbars = 1;
        int maxVbars = 1;

        int currHbars = 1;
        int currVbars = 1;

        for(int i =1;i<hBars.size();i++){
            if(hBars[i]-hBars[i-1]==1){
                currHbars++;
            }else currHbars=1;
            maxHbars = max(maxHbars,currHbars);
        }
        for(int i =1;i<vBars.size();i++){
            if(vBars[i]-vBars[i-1]==1){
                currVbars++;
            }else currVbars=1;
            maxVbars = max(maxVbars,currVbars);
        }

        int side = min(maxHbars,maxVbars)+1;

        return side*side;
    }
};