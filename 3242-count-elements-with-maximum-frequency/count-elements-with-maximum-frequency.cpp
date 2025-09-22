class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mpp;
        for(auto&it :nums){
            mpp[it]++;
        }
        int maxFreq = INT_MIN;
        for(auto it: mpp){
            maxFreq = max(maxFreq,it.second);
        }
        int cnt = 0;

        for(auto it:mpp){
            if(it.second==maxFreq){
                cnt+=it.second;
            }
        }
        return cnt;
    }
};