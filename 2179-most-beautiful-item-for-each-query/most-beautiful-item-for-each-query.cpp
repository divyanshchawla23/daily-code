class Solution {
public:
    int util(vector<vector<int>>& items, int a){
        int left = 0;
        int right = items.size()-1;
        int ans = 0;

        while(left<=right){
            int mid = left + (right-left)/2;

            if(items[mid][0]<=a){
                ans = max(ans,items[mid][1]);
                left = mid+1;
            }
            else right = mid-1;
        }

        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& q) {
        // [1,2],[2,4],[3,2],[3,5],[5,6]
        sort(items.begin(),items.end());
        int maxi = items[0][1];
        for(auto &it: items){
            it[1]=max(maxi,it[1]);
            maxi = max(maxi,it[1]);
        }
        vector<int> ans;

        for(auto& it: q){
            int x = util(items,it);
            ans.push_back(x);
        }

        return ans;
    }
};