class Solution {
public:
    int minDeletions(string s) {
        map<char , int > mpp;
        set<int> st;
        int res =0;

        for(int i =0;i<s.size();i++){
            mpp[s[i]]++;
        }

        for(auto it : mpp){
            while(it.second>0 && st.find(it.second)!=st.end()){
            
            
                it.second--;
                res++; 
            }
            st.insert(it.second);
        
        }
        return res;
    }
};