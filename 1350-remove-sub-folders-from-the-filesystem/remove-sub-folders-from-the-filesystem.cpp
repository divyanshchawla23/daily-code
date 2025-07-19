class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        set<string> st(folder.begin(), folder.end());
        vector<string> ans;

        for (auto it : folder) {
            string orignalString = it;
            bool flag = 0;
            while (it != "") {
                size_t position = it.find_last_of('/');
                it = it.substr(0, position);

                if (st.find(it) != st.end()) {
                    flag = 1;
                    break;
                }
            }

            if (!flag)
                ans.push_back(orignalString);
        }

        return ans;
    }
};