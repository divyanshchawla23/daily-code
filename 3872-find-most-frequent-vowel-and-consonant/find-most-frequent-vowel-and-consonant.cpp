class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
            return true;
        }
        return false;
    }
    int maxFreqSum(string s) {
        int maxCon = 0;
        int maxVow = 0;
        map<char,int>mpp;
        for(char &ch: s){
            mpp[ch]++;
        }
        for(auto &it : mpp){
            if(isVowel(it.first)){
                maxVow = max(maxVow,it.second);
            }
            else{
                maxCon = max(maxCon,it.second);
            }
        }


        return maxCon + maxVow;
    }
};