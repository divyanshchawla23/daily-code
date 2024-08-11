class Solution {
public:
    string reverseWords(string s) {
        s+=" ";
        stack<string> st;
        string res="";
        for(int i =0;i<s.size();i++){
            if(s[i]== ' ') 
            {if(!res.empty())
            {

            
                st.push(res);
                res= "";
            }}

            else res+=s[i];

        }

        string ans = "";
        while(st.size()!=1){
            ans+=st.top()+" ";
            st.pop();
            

        }
        ans+=st.top();
        return ans;
    }
};