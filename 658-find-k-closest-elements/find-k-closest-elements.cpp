class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> hp;
        vector <int> ans;

        for(int i =0;i<arr.size();i++){

            hp.push({abs(arr[i]-x),arr[i]});

            if(hp.size()>k){
                hp.pop();
            }
            
        }

        while(hp.size()>0){
            ans.push_back(hp.top().second);
            hp.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};