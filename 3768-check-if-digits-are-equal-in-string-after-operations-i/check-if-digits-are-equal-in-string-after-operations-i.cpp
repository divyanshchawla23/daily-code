class Solution {
public:
    bool hasSameDigits(string s) {
        
        int n = s.size();

        while(s.size()>2){
            string t = "";
            for(int i =0;i<s.size()-1;i++){
                int a = s[i]-'0';
                int b = s[i+1]-'0';
                int c = (a+b)%10;

                t.push_back(c);
            }
            cout << t << endl;
            s = t;
        }

        set<char>st;
        for(char c:s){
            st.insert(c);
        }
        for(auto it: st){
            cout << it << " ";
        }

        return st.size()==1;
        
    }
};