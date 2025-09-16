class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum = 0;
        set<int> st;
        for (auto& it : nums) {
            st.insert(it);
            sum += it;
        }

        double avg = (double)sum / nums.size();

        int cnt = max(1, (int)floor(avg) + 1);

        while (st.find(cnt) != st.end()) {
            cnt++;
        }

        return cnt;
    }
};