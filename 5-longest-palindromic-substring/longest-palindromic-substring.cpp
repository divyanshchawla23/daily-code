class Solution {
private: 
    bool isPalindrome(string &s, int i , int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        string ans = "";
        int length =0;
        for(int i =0;i<s.size();i++){
            for(int j =0;j<s.size();j++){
                if(isPalindrome(s,i,j)){
                    int currL = j-i+1;
                    if(currL > length){
                    length = currL;
                    ans = s.substr(i,currL);
                    }
                }
            }
        }
        return ans;
    }
};