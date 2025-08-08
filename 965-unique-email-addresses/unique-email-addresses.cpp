class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for (auto it : emails) {
            string fin = "";
            int size = it.find('@');
            for (int i = 0; i < size; i++) {
                if (it[i] == '.')
                    continue;
                if (it[i] == '+')
                    break;
                fin += it[i];
            }
            for (int i = size; i < it.size(); i++) {
                fin += it[i];
            }
            st.insert(fin);
        }

        return st.size();
    }
};