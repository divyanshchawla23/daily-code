typedef long long ll;
class Solution {
public:
    bool isPossible(vector<int>& time, ll mid, int tt) {

        ll trips = 0;

        for (auto& it : time) {

            trips += mid / it;
        }

        return (trips >= tt);
    }
    long long minimumTime(vector<int>& time, int tt) {
        ll ans = -1;
        ll left = 1;
        ll right = (ll)*min_element(time.begin(), time.end()) * tt;

        while (left <= right) {
            //ll mid = (left + (right-left)) / 2;
            ll mid = left + ((right - left) / 2);

            if (isPossible(time, mid, tt)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};