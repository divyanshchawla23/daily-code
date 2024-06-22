class Solution {
public:
    int maxDepth(string s) {
        int maxi =0;
        int cnt =0;

        for(int i =0;i<s.size();i++){
            if(s[i]=='('){
                cnt = cnt +1 ;
            maxi = max(maxi, cnt);
            }
            
             else if(s[i]==')'){
                cnt = cnt -1 ;
            }
        }
        return maxi;
    }
};