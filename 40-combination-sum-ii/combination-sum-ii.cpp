class Solution {
public:

void r( vector<int>& nums,int index,vector<int>& ans,vector<vector<int>>& res,int target ){


        if (target==0){
            
            res.push_back(ans);
            
            return  ;
            
        }
        
        


        for(int i =index;i<nums.size();i++){
        if(i!=index && nums[i]==nums[i-1]) {continue;}
        if(nums[i]>target) {break;}
        ans.push_back(nums[i]);
        r(nums,  i+1 , ans,res,target-nums[i]);
        ans.pop_back();
        
        }

        
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(),candidates.end());
         
        vector<int> ans;
        vector<vector<int>> res;
        r(candidates,0 , ans,res,target);
        return res;

    }
};