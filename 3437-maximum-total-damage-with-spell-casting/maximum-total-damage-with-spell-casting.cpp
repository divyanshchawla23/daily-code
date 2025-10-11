class Solution {
public:
    typedef long long ll;
    
    ll solve(ll ind, vector<ll>&nums,map<ll,ll>&mpp,ll n,vector<ll> &dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1) return dp[ind];
        ll skip = solve(ind+1,nums,mpp,n,dp);
        ll j = lower_bound(nums.begin()+ind+1,nums.end(),nums[ind]+3)-nums.begin();
        ll take = nums[ind]*mpp[nums[ind]]+solve(j,nums,mpp,n,dp);

        return dp[ind]=max(skip,take);
    }
    long long maximumTotalDamage(vector<int>& power) {
        map<ll,ll>mpp;
        for(auto &it:power){
            mpp[it]++;
        }
        vector<ll> nums;
        for(auto &it:mpp){
            nums.push_back(it.first);
        }
        sort(nums.begin(),nums.end());
        ll n = nums.size();


        vector<ll> dp(n+1,-1);
        return solve(0,nums,mpp,n,dp);
    }
};