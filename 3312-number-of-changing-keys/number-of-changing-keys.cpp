class Solution {
public:
    int countKeyChanges(string s) {
        char last = s[0];
        int n = s.size();
        int cnt =0;

        for(int i =1;i<n;i++){
            if(tolower(s[i])!=tolower(last)) 
            {cnt++;
            last = s[i];}
            else continue;
        }
        return cnt;
    }
};