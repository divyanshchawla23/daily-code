class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string s = to_string(n);
        map<char,int> mpp;

        for(char c: s){
            mpp[c]++;
        }

        int mini = INT_MAX;

        for(auto it: mpp){
            mini = min(it.second,mini);
        }
        int ans = INT_MAX;
        for(auto it: mpp){
            if(it.second==mini){
                ans = min(ans,(it.first-'0'));
            }
        }

        return (int)ans;

    }
};