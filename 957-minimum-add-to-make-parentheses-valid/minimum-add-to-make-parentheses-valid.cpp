class Solution {
public:
    int minAddToMakeValid(string s) {
        stack <char > st ;
        int cnt =0;

        for(int i =0;i< s.size();i++){
            if(st.empty() && s[i]==')'){
                cnt++;
            
            }

            else if(!st.empty() && s[i]==')'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        return st.size()+cnt;
    }
};