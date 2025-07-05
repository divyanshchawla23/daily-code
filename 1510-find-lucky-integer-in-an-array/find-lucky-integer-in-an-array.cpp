class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mpp;
        int ans = -1;

        for(auto it: arr){
            mpp[it]+=1;
        }

        for(auto it:mpp){
            if(it.first==it.second){
                if(it.first>ans)
                    ans = it.first;
            }
        }



        return ans;
    }
};