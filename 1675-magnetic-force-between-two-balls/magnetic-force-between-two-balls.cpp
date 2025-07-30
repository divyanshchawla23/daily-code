class Solution {
public:
    bool canWePlace(vector<int>& nums, int mid, int m){
        int lastPlace = nums[0];
        int cowsCnt =1;

        for(int i =1;i<nums.size();i++){
            if(nums[i]-lastPlace>=mid){
                cowsCnt += 1;
                lastPlace = nums[i];
            }

        }
        if(cowsCnt>=m) return true;
        else return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int maxDist = *max_element(position.begin(),position.end()) 
        - *min_element(position.begin(),position.end());
        int ans = INT_MIN;
        int n = position.size();
        int l =1;
        int r = maxDist;

        while(l<=r){
            int mid = (l+r)/2;
            
            if(canWePlace(position,mid,m)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
            
        }
        return ans;
    }
};