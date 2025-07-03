class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";

        while(s.size()<k){
            int n = s.size();
            for(int i =0;i<n;i++){
                if(s[i]=='z'){
                    s+='a';
                    if(s.size()>=k) break;
                }else{
                    s+=s[i]+1;
                    if(s.size()>=k) break;
                }
            }
        }
        return s[k-1];
    }
};