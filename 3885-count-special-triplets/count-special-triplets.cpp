class Solution {
public:
    const int mod = 1e9+7;
    int specialTriplets(vector<int>& nums) {
        long long cnt = 0;


        map<int,int>mpp1;
        map<int,int>mpp2;

        for(auto &it: nums){
            mpp1[it]++;
        }

        for(auto &it: nums){
            mpp1[it]--;

            if(mpp1.find(it*2)!=mpp1.end() && mpp2.find(it*2)!=mpp2.end()){
                cnt = (cnt + (1LL * mpp1[it*2] * mpp2[it*2]) % mod) % mod;
            }

            mpp2[it]++;
        }

        return (int)cnt%mod;
    }
};