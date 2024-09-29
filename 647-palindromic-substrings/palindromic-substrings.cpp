class Solution {
public:
    int helper(string&s , int left, int right){
        int cnt =0;

        while(left>=0 && right<s.size() && s[left]==s[right]){
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int cnt =0;
        for(int i =0;i< s.size();i++){
            int even = helper(s,i,i+1);
            int odd = helper(s,i,i);
            cnt+= even+odd;
        }
        return cnt;
    }
};