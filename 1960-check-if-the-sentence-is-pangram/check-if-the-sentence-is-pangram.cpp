class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set st(sentence.begin(),sentence.end());
        if(st.size()!=26) return false;
        else return true;
    }
};