class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> lost_map;
        set<int>st;
        vector<vector<int>> ans(2);

        for(auto&it: matches){
            lost_map[it[1]]++;
        }

        for(auto&it:lost_map){
            if(it.second==1){
                ans[1].push_back(it.first);
            }
        }

        for(auto &it: matches){
            if(lost_map.find(it[0])==lost_map.end()){
                st.insert(it[0]);
            }
        }
        for(auto &it:st){
            ans[0].push_back(it);
        }

        //sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());

        return ans;
    }
};