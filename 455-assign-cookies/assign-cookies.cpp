class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();

        int left = 0;
        int right =0;
        int cnt =0;

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        while(right<m && left<n ){

            if(g[right]<=s[left]){
                cnt++;
                right++;
            }
            left++;
        }
        return cnt;
    }
};