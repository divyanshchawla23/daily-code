class Solution {
private:
    string helper(string& s, int& x, int& ans, string &bigger) {
        stack<char> st;
        for (char it : s) {
            if (!st.empty() && it == bigger[1] && st.top() == bigger[0]) {
                st.pop();
                ans += x;
            } else
                st.push(it);
        }
        string ss = "";
        while (!st.empty()) {
            ss += st.top();
            st.pop();
        }
        reverse(ss.begin(), ss.end());
        return ss;
    }

    void helper1(string& s, int& x, int& ans,string &smaller) {
        stack<char> st;
        for (auto it : s) {
            if (!st.empty() && it == smaller[1] && st.top() == smaller[0]) {
                st.pop();
                ans += x;
            } else
                st.push(it);
        }
    }

public:
    int maximumGain(string s, int x, int y) {
        string biggerS;
        string smallerS;
        if (x >= y) {
            biggerS = "ab";
            smallerS = "ba";
        } else {
            biggerS = "ba";
            smallerS = "ab";
        }
        int bigger = max(x, y);
        int smaller = min(x, y);
        int ans = 0;
        string newString1 = helper(s, bigger, ans, biggerS);
        cout << newString1;
        helper1(newString1, smaller, ans,smallerS);

        return ans;
    }
};