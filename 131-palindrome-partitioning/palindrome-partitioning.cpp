class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        func(0,s,ans,res);
        return res ;
        
    }

    void func(int index, string s, vector<string> &ans,vector<vector<string>>& res){
        if(index >= s.size()){
            res.push_back(ans);
            return ;
        }
        for(int i = index; i < s.size();i++){
            if(isPalindrome(s,index, i )){
                ans.push_back(s.substr(index , i-index+1));
                func(i+1,s,ans,res);
                ans.pop_back();
            }
        }
    }

    bool isPalindrome(string &s ,int left, int right){
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++; right--;
        }
        return true;
    }
        
    
};