class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;

        map<int, pair<int, int>> mpp1; // X -> min,max Y
        map<int, pair<int, int>> mpp2; // Y-> min,max X

        for (auto& it : buildings) {

            int x = it[0];
            int y = it[1];

            if (mpp1.find(x) == mpp1.end()) {
                mpp1[x].first = INT_MAX;
                mpp1[x].second = INT_MIN;
            }
            if (mpp2.find(y) == mpp2.end()) {
                mpp2[y].first = INT_MAX;
                mpp2[y].second = INT_MIN;
            }

            mpp1[x].first = min(mpp1[x].first, y);
            mpp1[x].second = max(mpp1[x].second, y);

            mpp2[y].first = min(mpp2[y].first, x);
            mpp2[y].second = max(mpp2[y].second, x);
        }



        for (auto& it : buildings) {

            int x = it[0];
            int y = it[1];

            if (mpp1[x].first < y && y < mpp1[x].second &&
                mpp2[y].first < x && x < mpp2[y].second) {
                ans++;
            }
        }
        return ans;
    }
};