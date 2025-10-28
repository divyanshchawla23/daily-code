class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<int>st;
        for(auto it: nums){
            int a = stoi(it,0,2);
            st.insert(a);
        }
        string result = "";
        int n = nums.size();
        for(int i =0;i<=pow(2,n)-1;i++){
            if(st.find(i)==st.end()){
                result = bitset<16>(i).to_string();
                return result.substr(16-n,n);  
            }
        }
        return "";
    }
};