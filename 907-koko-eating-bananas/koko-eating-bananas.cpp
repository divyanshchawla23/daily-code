class Solution {
private: 

    long long maxEl(vector<int>& piles){
        int maxi= INT_MIN;
        for (int i =0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi ;
    }


    long long  find(vector<int>& nums, int h){
        long long total = 0;

        for(int i =0;i<nums.size();i++){
            total += ceil((double)nums[i]/(double)h);
        }
        return total;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int ans = INT_MAX;
        int low = 1;
        int high = maxEl(piles);
        while(low<=high){
            int mid = low + ((high-low) /2);

            long long totalTime = find(piles,mid);

            if(totalTime<=h){
                ans = mid;
                high = mid-1;
            }
            
            else low = mid+1;
        }
        return ans;
    }
};