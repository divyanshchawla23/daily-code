class Solution {
public:
    string customSortString(string order, string s) {
        map<char, int> mpp;
        string ans = "";

        for(int i =0;i<s.size();i++){
            mpp[s[i]]++;
        }

        for(int i =0;i<order.size();i++){
            if(mpp.find(order[i])==mpp.end()){
                continue;
            }

            for(int j =1 ;j<=mpp[order[i]];j++){
                ans += order[i];
            }
            mpp.erase(order[i]);
        }


        for(auto it: mpp){
            for(int i =1 ;i<=it.second;i++){
                ans += it.first;
            }
        }

        return ans;





    }
};