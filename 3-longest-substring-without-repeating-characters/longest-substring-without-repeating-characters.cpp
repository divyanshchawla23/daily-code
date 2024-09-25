class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;
        int right =0;
        int maxi=0;
        map<char,int> mpp;

        int n = s.size();

        while(right<n){
            if(mpp.find(s[right])!=mpp.end()){
                if(mpp[s[right]]>=left){
                    left= mpp[s[right]]+1;
                }
            }

            int len = right-left+1;
            maxi = max(maxi , len);

            mpp[s[right]]= right;
            right++;
        }

        return maxi;
    }
};