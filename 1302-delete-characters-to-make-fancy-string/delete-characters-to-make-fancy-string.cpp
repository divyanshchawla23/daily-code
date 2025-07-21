class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        ans+=s[0];
        int cnt  =1;
        for(int i =1;i<s.size();i++){
            if(ans.back()!=s[i]){
               
                cnt=1;
            }else{
               
                cnt+=1;
                if(cnt>2){
                    ans.pop_back();
                }
            } ans+=s[i];
        }
        return ans;
    }
};