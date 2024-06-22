class Solution {
public:
    int beautySum(string s) {
        int sum =0;
        for(int i =0;i<s.size();i++){
            map <char , int> mpp;

            for(int j=i;j<s.size();j++){
                mpp[s[j]]++;

                int mini= INT_MAX;
                int maxi = INT_MIN;

                for(auto it : mpp){
                    if(it.second>maxi){
                        maxi = it.second;
                    }

                    if(it.second<mini){
                        mini = it.second;
                    }
                }
                sum += (maxi - mini);
            }
        }
            return sum;
    }
};