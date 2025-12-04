class Solution {
public:
    int countCollisions(string s) {
        int n = s.size();
        int ans = 0;

        int i = 0;
        while(i<n&&s[i]=='L'){
            i++;
        }
        int j = n-1;
        while(j>=0&&s[j]=='R'){
            j--;
        }

        while(i<=j){
            if(s[i]!='S'){
                ans++;
            }
            i++;
        }

        return ans;
    }
};