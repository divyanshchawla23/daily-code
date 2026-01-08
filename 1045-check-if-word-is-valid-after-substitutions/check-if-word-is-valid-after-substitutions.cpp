class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for (auto& it : str) {
            st.push(it);

            if (st.size() >= 3) {
                char c = st.top();
                st.pop();
                char b = st.top();
                st.pop();
                char a = st.top();
                st.pop();

                if (c == 'c' && b == 'b' && a == 'a') {
                    continue;
                } else {
                    st.push(a);
                    st.push(b);
                    st.push(c);
                }
            }
        }

        return st.empty();
    }
};