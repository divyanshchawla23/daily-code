class Solution {
public:
    bool isAnagram(string a, string b){
        map<char,int> mpp;
        for(char &c : a){
            mpp[c]++;
        }
        for(char &c : b){
            mpp[c]--;
        }

        for(auto it: mpp){
            if(it.second!=0) return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;

        int n = words.size();

        res.push_back(words[0]);

        for(int i =1;i<n;i++){
            if(isAnagram(words[i],res.back())){
                continue;
            }else{
                res.push_back(words[i]);
            }
        }
        return res;
    }
};