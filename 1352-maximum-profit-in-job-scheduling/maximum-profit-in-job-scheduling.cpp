class Solution {
public:
    int binarySearch(vector<vector<int>>& events, int x) {
        int low = 0;
        int high = events.size() - 1;
        int ans = events.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (events[mid][0] >= x) {
                ans = mid;
                high = mid - 1;
            }

            else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int helper(int ind, vector<vector<int>>& events, int n, vector<int>& dp) {

        if (ind >= n)   return 0;
        if (dp[ind] != -1)  return dp[ind];

        int pick = events[ind][2] + helper(binarySearch(events, events[ind][1]), events, n, dp);

        int not_pick = helper(ind + 1, events, n, dp);

        return dp[ind] = max(pick, not_pick);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {

        int n = startTime.size();
        vector<vector<int>> events(n);
        vector<int> dp(50001, -1);

        for (int i = 0; i < n; i++) {
            events[i].push_back(startTime[i]);
            events[i].push_back(endTime[i]);
            events[i].push_back(profit[i]);
        }

        sort(events.begin(), events.end());

        return helper(0, events, n, dp);
    }
};