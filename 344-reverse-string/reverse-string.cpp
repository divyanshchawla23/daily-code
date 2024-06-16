class Solution {
public:
    void rev(vector<char>& s, int i){
        int n = s.size();
        if(i>=n-i-1){
            return ;
        }
        swap(s[i],s[n-i-1]);
        rev(s,  i+1);
    }
    void reverseString(vector<char>& s) {
        int i =0;
         rev(s,  i);
    }
};