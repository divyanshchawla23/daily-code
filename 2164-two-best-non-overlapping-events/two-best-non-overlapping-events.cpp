class Solution {
public:
    int bs(vector<vector<int>>& events, int val) {
        int l = 0;
        int r = events.size() - 1;
        int ans = events.size();

        while (l <= r) {
            int mid = (l + r) / 2;

            if (events[mid][0] > val) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
    int helper(int index, vector<vector<int>>& events, int n, int cnt,vector<vector<int>> &dp) {
        if (cnt == 2 || index >= n) {
            return 0;
        }

        if(dp[index][cnt]!=-1) return dp[index][cnt];

        int pick = events[index][2] +
                   helper(bs(events, events[index][1]), events, n, cnt + 1,dp);

        int not_pick = helper(index + 1, events, n, cnt,dp);

        return dp[index][cnt]=max(pick, not_pick);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int n = events.size();
        int cnt = 0;
        vector<vector<int>> dp(n+1,vector<int>(3,-1));

        return helper(0, events, n, cnt,dp);
    }
};