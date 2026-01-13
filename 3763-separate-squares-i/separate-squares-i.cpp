class Solution {
public:
    bool isSame(double mid, vector<vector<int>>& squares,double totalArea){
        double areaBelow = 0.0000;
        for(auto &it : squares){
            double x = it[0];
            double y = it[1];
            double z = it[2];

            if(y+z<=mid){
                areaBelow += (double)z*(double)z;
            }else if(y<mid){
                areaBelow+= double(mid-y) * double(z);
            }
        }
        return (areaBelow >= totalArea/2.0000);
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX;
        double high = INT_MIN;
        double ans = -1.0000;
        double totalArea = 0.0000;

        for(auto &it : squares){
            double x = it[0];
            double y = it[1];
            double z = it[2];

            low = min(low,y);
            high = max(high,y+z);
            totalArea += (double)z*(double)z;
        }

        while(high-low > 1e-5){

            double mid = (low+high)/2;

            if(isSame(mid,squares,totalArea)){
                ans = mid;
                high = mid;
            }else{
                low = mid;
            }

        }
        return ans;
    }
};