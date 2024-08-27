class Solution {

public:
    struct mycom{
        bool operator()(pair<int,int> const &p1,pair<int,int>p2 )
        {
            if(p1.first==p2.first)
            {
                return p2.second>p1.second;
            }
            return p1.first>p2.first;
        }
    };
    vector<int> frequencySort(vector<int>& nums) {

        vector <int> ans ;

        map <int , int > mpp;

        priority_queue< pair<int, int>, 
        vector <pair<int , int >>, 
        mycom> hp;


        for(int i =0;i<nums.size();i++){
            mpp[nums[i]] += 1;
        }

        for(auto it : mpp){
            hp.push({it.second , it.first});

        }

        while(hp.size()>0){
            int freq= hp.top().first;
            int el = hp.top().second;
            for(int i =1;i<=freq;i++){
                ans.push_back(el);
            }
            hp.pop();
        }

      //  sort(ans.begin(), ans.end());

        return ans ;
        
    }
};