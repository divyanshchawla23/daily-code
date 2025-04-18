class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string s = countAndSay(n - 1);

        string res = "";

        char c = s[0];
        int cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                cnt++;
            } else {
                res += to_string(cnt) + c;
                c = s[i];
                cnt = 1;
            }
        }
        res += to_string(cnt) + c;
        return res;
    }
};