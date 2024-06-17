class Solution {
public:

void r( vector<int>& nums,
        int index,
        vector<int>& ans,
        vector<vector<int>>& res,
        int target )

        {
        if (index >= nums.size()){
            if(target==0){
            res.push_back(ans);
            }
            return  ;
            
        }

        if(nums[index]<=target){
        ans.push_back(nums[index]);
        r(nums,  index , ans,res,target-nums[index]);
        ans.pop_back();

        }

        r(nums,  index+1 , ans,res,target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
         int index = 0;
        vector<int> ans;
        vector<vector<int>> res;
          r(candidates,index , ans,res,target);
          return res;

    }
};