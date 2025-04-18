class Solution {
private:
    int biggerThan(vector<int>& v, int n) {
        int ans = -1;
        int left = 0;
        int right = v.size()-1;
        while(left<=right){
            int mid = (left + right) / 2;
            if(v[mid]>n){
                ans = v[mid];
                right = mid -1;
            }
            else left = mid+1;

        }
        return ans;
    }
    void initilizeMap(string& s, map<char, vector<int>>& mpp) {
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]].push_back(i);
        }
    }

public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int c = 0;
        map<char, vector<int>> mpp;
        initilizeMap(s, mpp);

        for (string str : words) {
            bool isSub = true;
            int prevInd = -1;
            for (int i = 0; i < str.size(); i++) {
                int big = biggerThan(mpp[str[i]], prevInd);
                if (big != -1) {
                    prevInd = big;
                } else {
                    isSub = false;
                    break;
                }
            }
            if (isSub)
                c++;
        }

        return c;
    }
};