class Solution {
public:

    void r(vector<int>& nums,int index,vector<int>& ans,vector<vector<int>>& res){
        if (index >= nums.size()){
             res.push_back(ans);
            return  ;
        }

        ans.push_back(nums[index]);
        r(nums,  index+1 , ans,res);
        ans.pop_back();
        r(nums,  index+1 , ans,res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {

         int index = 0;
        vector<int> ans;
        vector<vector<int>> res;
          r(nums,index , ans,res);
          return res;
        
        
    }
};