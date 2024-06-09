class Solution {
public:

    bool check(int i,int n,vector<char>& ans){
        if(i>=n/2){
            return true;
        }
        if(ans[i]==ans[n-i-1]){
            return check(i+1,n,ans);
        }
        return false;
    }

    bool isPalindrome(string s) {
        vector<char>ans;
        for(char c : s){
            if(isalnum(c)){
                ans.push_back(tolower(c));
            }
        }
        int n = ans.size();
        return check(0,n,ans);
    }
};