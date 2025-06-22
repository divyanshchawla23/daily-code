class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        int n = s.size();
        int curr = 0;

        while (curr < n) {
            string temp = s.substr(curr, k);
            if (temp.size() < k) {
                while(temp.size()<k){
                    temp+=fill;
                }
            }
            res.push_back(temp);
            curr += k;
        }
        return res;
        
    }
};