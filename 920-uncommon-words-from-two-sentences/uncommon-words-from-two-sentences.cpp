class Solution {
public:
    void addSstoMap(string&s,unordered_map<string,int> &mpp){
        stringstream ss(s);
        string str = "";

        while(getline(ss,str,' ')){
            mpp[str]++;
        }

    }
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> mpp;
        addSstoMap(s1,mpp);
        addSstoMap(s2,mpp);
        vector<string>ans;

        for(auto it: mpp){
            if(it.second==1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};