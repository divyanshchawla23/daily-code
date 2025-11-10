class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mpp;
        int left =0;
        int right =0;
        int n = s.size();
        int ans = 0;

        while(right<n){

            if(mpp.find(s[right])!=mpp.end()){
                if(mpp[s[right]]>=left)
                    left = mpp[s[right]]+1;
            }

            int len = right-left+1;
            ans = max(ans,len);

            mpp[s[right]]=right;
            right++;
        }

        return ans;
    }
};