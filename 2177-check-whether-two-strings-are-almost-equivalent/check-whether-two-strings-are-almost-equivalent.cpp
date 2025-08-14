class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        map<char, int> mpp1, mpp2;
        
        for (char c : word1) mpp1[c]++;
        for (char c : word2) mpp2[c]++;

        set<char> allChars;
        for (auto &p : mpp1) allChars.insert(p.first);
        for (auto &p : mpp2) allChars.insert(p.first);
        
        for (char c : allChars) {
            if (abs(mpp1[c] - mpp2[c]) > 3) {
                return false;
            }
        }
        return true;
    }
};