class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> mpp;

        for(char &c: s){
            mpp[c]++;
        }
        for(char &c: t){
            mpp[c]--;
        }
        for(auto it: mpp){
            if(it.second<0){
                return it.first;
            }
        }
        return '#';
    }
};