class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        int m = people.size();

        vector<int> bloomTime;
        vector<int> dieTime;
        vector<int> ans;

        for(auto&it: flowers){
            bloomTime.push_back(it[0]);
            dieTime.push_back(it[1]);
        }

        sort(bloomTime.begin(),bloomTime.end());
        // 1 3 4 9
        sort(dieTime.begin(),dieTime.end());
        // 6 7 12 13

        // int flowersBloom = upper_bound(bloomTime.begin(),bloomTime.end(),3) - bloomTime.begin();
        //     cout << "upper-> " << flowersBloom << " ";
        //     cout << "upper-> " << bloomTime[flowersBloom] << " ";

        for(auto&it : people){

            int flowersBloom = upper_bound(bloomTime.begin(),bloomTime.end(),it) - bloomTime.begin();

            int flowersDie = lower_bound(dieTime.begin(),dieTime.end(),it) - dieTime.begin();

            ans.push_back(flowersBloom-flowersDie);

        }

        return ans;
    }
};