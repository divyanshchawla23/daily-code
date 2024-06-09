class Solution {
public:

    bool check(vector<char>&s,int n, int i){

        if(i>=n/2) return true;
        if(s[i]!=s[n-i-1]) return false;
        return check(s,n,i+1);
        
    }
    bool isPalindrome(string s) {

        vector<char>ans;

        for(auto it : s){
            if(isalnum(it)){
                ans.push_back(tolower(it));
            } 
        }

        int i =0;
        int n = ans.size();

         return check (ans,n,i);
        
    }
};