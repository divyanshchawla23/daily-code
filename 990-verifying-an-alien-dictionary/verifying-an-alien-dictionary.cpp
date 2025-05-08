class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char, int> mpp;
        for (int i = 0; i < order.size(); i++) {
            mpp[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {

            string s1 = words[i];
            string s2 = words[i + 1];
            int len = min(s1.size(), s2.size());
            bool comp = false;
            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    if (mpp[s1[j]] > mpp[s2[j]])    return false;
                    comp = true;
                    break;
                }
            }

            if(!comp && s1.size() > s2.size()) return false;
        }
        return true;
    }
};