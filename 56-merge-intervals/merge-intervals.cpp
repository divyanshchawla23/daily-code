class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        sort(interval.begin(),interval.end());
        vector<vector<int>>ans ;


        for(auto it: interval){

            if(ans.empty() || it[0]>ans.back()[1]){
                ans.push_back(it);
            }
            else{
                ans.back()[1]= max(it[1],ans.back()[1]);
            }

        }

        return ans;



        
    }
};