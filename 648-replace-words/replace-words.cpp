class Solution {
public:
    string util(string &s, set<string> &st){
        int n = s.size();
        string str = "";
        for(int i =0;i<n;i++){
            if(st.find(str)!=st.end()){
                return str;
            }
            str+=s[i];

        }
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<string> st(dictionary.begin(),dictionary.end());
        string ans = "";

        stringstream ss(sentence);
        string str;

        while(getline(ss,str, ' ')){
            if(!ans.empty()){
                ans+=' ';
            }
            ans+=util(str,st);
        }

        return ans;
    }
};