class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for(int i =0;i< s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;

                else{
                    char c = st.top();
                    st.pop();
                    if( (c=='(' && s[i]==')') || (c=='[' && s[i]==']') || (c=='{' && s[i]=='}') ){
                        continue;
                    }
                    else return false;
                }
            }
        }
        return st.empty();
    }
};