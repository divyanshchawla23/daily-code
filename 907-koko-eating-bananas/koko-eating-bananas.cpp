class Solution {
public:
    long long helper(vector<int>&piles,int mid){
        
        long long  hrs =0;
        for(int i =0;i<piles.size();i++){
            hrs+=ceil(double(piles[i])/double(mid));
        }
        return hrs;

    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l =1;
        int r = *max_element(piles.begin(),piles.end());
        int ans =0;

        while(l<=r){
            int mid = (l+r)/2;
            long long totalHrs = helper(piles,mid);
            if(totalHrs<=h){
                ans = mid;
                r =mid-1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};