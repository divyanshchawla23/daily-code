class Solution {
public:

    int maxEl(vector<int>& piles){
        int maxi= INT_MIN;
        for (int i =0;i<piles.size();i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi ;
    }

    long long totalHours(vector<int>& piles, int hrs) {
        long long total = 0;
        for(int i = 0; i < piles.size(); i++) {
            total += ceil((double)piles[i]/(double)hrs);
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = maxEl(piles);
        int ans = INT_MAX;

        while(left<=right){

            int mid = left + ((right - left) / 2);
            long long totalTime = totalHours(piles, mid);

            if (totalTime<= h){
                ans = mid;
                right = mid -1;

            }

            else left = mid +1;
        }
        return ans ;
    }

};