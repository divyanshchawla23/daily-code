class Solution {
public:
    bool codeCheckUtil(string &s){
        if (s.empty()) return false; 
        for(char &c: s){
            if(!isalnum(c) && c!='_') return false;
        }
        return true;
        
    }
    bool businessCheckUtil(string &s){
        if(s=="grocery"||s=="electronics"||s=="pharmacy"||s=="restaurant") return true;
        else return false;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<string> ans;
        vector<pair<string,string>> v;

        for(int i =0;i<n;i++){
            string cc = code[i];
            string bb = businessLine[i];
            bool aa = isActive[i];

            if(aa && codeCheckUtil(cc) && businessCheckUtil(bb)){
                v.push_back({bb,cc});
            }
        }

        sort(v.begin(),v.end());

        for(auto &it: v){
            ans.push_back(it.second);
        }

        return ans;
    }
};