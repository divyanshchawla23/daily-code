class Solution {
public:
    bool isValid(string s) {
        if (s.size()>1 && s[0] == '0') {
            return false;
        }

        int a = stoi(s);

        if (a <= 255)
            return true;
        return false;
    }
    void solver(string& s, int ind, int parts, string curr, vector<string>& ans,
                int n) {

        if (ind >= n && parts == 4) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }

        if (ind + 1 <= n) {
            solver(s, ind + 1, parts + 1, curr + s.substr(ind, 1) + '.', ans,
                   n);
        }
        if (ind + 2 <= n && isValid(s.substr(ind, 2))) {
            solver(s, ind + 2, parts + 1, curr + s.substr(ind, 2) + '.', ans,
                   n);
        }
        if (ind + 3 <= n && isValid(s.substr(ind, 3))) {
            solver(s, ind + 3, parts + 1, curr + s.substr(ind, 3) + '.', ans,
                   n);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;

        int n = s.size();

        if (n > 12) {
            return {};
        }

        string curr = "";
        solver(s, 0, 0, curr, ans, n);

        return ans;
    }
};