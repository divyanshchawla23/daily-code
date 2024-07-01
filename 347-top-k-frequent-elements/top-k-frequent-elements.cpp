class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector <int> ans;
        unordered_map<int, int> mpp;
        priority_queue< pair<int,int>, 
                        vector <pair<int,int>>, 
                        greater <pair<int,int>> > hp;
        

        for(int i =0;i<nums.size();i++){
            mpp[nums[i]]+=1;
        }

        for(auto it : mpp){
            hp.push({it.second , it.first});

            if(hp.size()>k){
                hp.pop();
            }
        }

        while(hp.size()>0){
            ans.push_back(hp.top().second);
            hp.pop();
        }

        return ans;

        
        
    }
};