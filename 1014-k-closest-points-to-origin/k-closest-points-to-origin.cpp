class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         priority_queue<pair<int,pair<int,int>>>hp;
        vector<vector<int>> ans;

        for(int i =0;i<points.size();i++){

            hp.push({points[i][0]*points[i][0]+points[i][1]*points[i][1],
            {points[i][0],points[i][1]}});

            if(hp.size()>k){
                hp.pop();
            }
        }


        while(hp.size()>0){
            pair<int,int> p = hp.top().second;
            ans.push_back(vector<int> {p.first,p.second});
            hp.pop();
        }
        return ans;
    }
};