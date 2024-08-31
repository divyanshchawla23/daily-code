class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;
        int right =0;
        int n = s.size();
        int maxLen =0;
        if(n==0) return 0;
        map<char , int > mpp;
        

        while(right<n){
            if(mpp.find(s[right])!=mpp.end()){
                if(mpp[s[right]]>= left){
                    left = mpp[s[right]]+1;
                }
            }
            int len = right-left+1;
            maxLen = max(maxLen , len);
            mpp[s[right]] = right; //adding to hashmap
            right++;
        }
        return maxLen;
    }
};