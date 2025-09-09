class Solution {
public:
    int lengthOfLastWord(string s) {
        string ans = "";
        string temp = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (temp != "")
                    ans = temp;
                temp = "";
            } else
                temp += s[i];
        }

        if (temp != "")
            ans = temp;

        cout << ans;

        return ans.size();
    }
};