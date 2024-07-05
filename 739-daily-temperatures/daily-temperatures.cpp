class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size();
       stack <pair<int,int>> s ;
        vector<int> ans;
        
        for( int i =n-1;i>=0;i--){
            if(s.empty()) ans.push_back(0);

            else if (s.size()!=0 && s.top().first>nums[i]){
                ans.push_back(s.top().second-i );
            }

            else if (s.size()!=0 && s.top().first<=nums[i]){
                while(s.size()!=0 && s.top().first<=nums[i]){
                    s.pop();
                }
                if(s.size()==0){
                    ans.push_back(0);
                }
                else ans.push_back(s.top().second- i);
            }
            s.push({nums[i], i});
            
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};