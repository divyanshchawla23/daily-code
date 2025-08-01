class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for(int  i=0;i<nums.size();i++){
            int need = target -nums[i];
            if(mp.find(need)!=mp.end()){

                return {i,mp[need]};
                
            }


            mp[nums[i]] = i;
        }

        return {};
    }
};