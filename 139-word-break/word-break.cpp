class Solution {
    int dp[301];
private:
    bool helper(int i, string &str, set<string> &st){
        if(i>=str.size()) return true;
        if(dp[i]!=-1) return dp[i];
        string temp ="";

        for(int k =i ;k<str.size();k++){
            temp = temp + str[k];
            if(st.find(temp)!=st.end()){
                if (helper(k+1,str,st)) return dp[i] =true;
            }
        }

        return dp[i]=false;


    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        int index =0;
        set<string> st;
        for(auto it : wordDict){
            st.insert(it);
        }
        return helper(index , s, st);
    }
};