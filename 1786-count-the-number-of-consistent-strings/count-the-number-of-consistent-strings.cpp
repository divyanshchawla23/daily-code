class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        set<char> st1;
        for (auto& it : allowed) {
            st1.insert(it);
        }
        for (auto word : words) {
            bool flag = 1;
            for (auto it : word) {
                if (st1.find(it) == st1.end()) {
                    flag = 0;
                }
            }
            if (flag)
                cnt++;
        }
        return cnt;
    }
};