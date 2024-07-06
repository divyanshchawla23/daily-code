class Solution {
public:
    int characterReplacement(string s, int k) {
       int left =0 , right = 0 , maxlen = 0 , maxfreq=0;
       map <char,int> mpp;

       while(right< s.size()){
            mpp[s[right]]++;
            maxfreq = max(maxfreq,mpp[s[right]]);

            while((right -left +1 ) - maxfreq> k){
                mpp[s[left]]--;
                maxfreq= 0;
                for(auto it : mpp){
                    maxfreq = max(maxfreq, it.second);
                }
                left=left+1;
            }

            if ((right -left +1 ) - maxfreq <= k){
                maxlen= max(maxlen , (right-left+1));
                
            }
            right++;

       } 
       return maxlen;
    }
};