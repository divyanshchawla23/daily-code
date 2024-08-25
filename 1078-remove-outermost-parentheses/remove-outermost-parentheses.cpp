class Solution {
public:
    string removeOuterParentheses(string s) {

        string res = "";
        int cnt =0;

        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;

            }
            else if(s[i]==')'){
                cnt--;
            }

            if(cnt==1 && s[i]=='(' || cnt == 0){
                continue;
            }
            else{
                res += s[i];
            }
        }
        return res;
        
    }
};