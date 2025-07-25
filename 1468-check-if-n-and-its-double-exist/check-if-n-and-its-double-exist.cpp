class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mpp;
        for(int i =0;i<arr.size();i++){
            if(
                mpp.find(2*arr[i])!=mpp.end() || 
                ((arr[i]%2==0)&&mpp.find(arr[i]/2)!=mpp.end())
            )
            {
                return true;
            }
            mpp[arr[i]]=i;
        }
        return false;
    }
};