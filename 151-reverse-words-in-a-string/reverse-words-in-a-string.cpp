class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(),s.end());
        int i =0;
        int j =0;

        int k =0;

        while(k<n){
            while(k<n && s[k]!= ' '){
                s[j]=s[k];
                k++;j++;
            }
            if(i<j) {
                reverse(s.begin()+i,s.begin()+j);
                s[j]=' ';
                j++;   
                i = j;
            }
            k++;

        }
        return s.substr(0,j-1);
    }
};