class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
         vector<vector<int>> ans;
        for(int i =0;i<nums.size();i++){
            if(ans.empty()|| ans.back()[1]<nums[i][0]){
                ans.push_back(nums[i]);
            }
            else {
                ans.back()[1]= max(ans.back()[1],nums[i][1]);
            }
        }
        return ans ;
    }
};