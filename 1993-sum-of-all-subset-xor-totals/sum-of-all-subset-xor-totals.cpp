class Solution {
public:
    void solve (int i,vector<int>& nums, vector<int>& temp, vector<vector<int>>& sub ){

        if(i == nums.size()){
            sub.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        solve(i+1,nums,temp,sub);
        temp.pop_back();
        solve(i+1,nums,temp,sub);

    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> sub;
        vector<int>temp;
        int res =0;

        solve(0,nums,temp,sub);

        for(auto &it: sub){
            int xr = 0;
            for(int &i :it){
                xr ^= i;
            }
            res+=xr;
        }

        return res;
    }
};