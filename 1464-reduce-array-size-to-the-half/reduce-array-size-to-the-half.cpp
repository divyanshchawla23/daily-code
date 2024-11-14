class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        map<int,int> mpp;
        for(int i =0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        
        vector<int> v;
        
        for(auto it:mpp){
            v.push_back(it.second);
        }
        
        sort(v.rbegin(),v.rend());
        
        int m = v.size();
        int cnt=0;
    
        int removed = 0;
        
        for(int i = 0; i < v.size(); i++) {
            removed += v[i];
            cnt++;
            if(removed >= n / 2) {
                return cnt;
            }
        }
        return cnt;
        
        
    }
};