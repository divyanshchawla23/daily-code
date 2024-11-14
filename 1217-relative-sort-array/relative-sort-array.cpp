class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mpp;
        vector<int> ans;

        for(int i =0;i<arr1.size();i++){
            mpp[arr1[i]]++;
        }

        for(int i=0;i<arr2.size();i++){
            for(int j=1;j<=mpp[arr2[i]];j++){
                ans.push_back(arr2[i]);
            }
            mpp.erase(arr2[i]);
        }

        
        for(auto it:mpp){
            for(int i =1;i<=it.second;i++){
                ans.push_back(it.first);
            }
        }
        
        return ans;

    }
};