class Solution {
public:
    bool isPossible(int bananas, vector<int>&piles,int h){
        long long hours = 0;
        for(auto &it: piles){
            hours+= ceil((double)it/(double)bananas);
        }
        
        if(hours<=h) return true;
        else return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int ans = -1;
        int l =1;
        int r = *max_element(piles.begin(),piles.end());
        while(l<=r){
            int mid = (l+r)/2;

            if(isPossible(mid,piles,h)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return ans;
    }
};