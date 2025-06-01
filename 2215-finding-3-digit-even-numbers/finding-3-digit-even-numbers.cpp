class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> st;
        vector<int> ans;
        int n = digits.size();

        for(int i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                for(int k =0;k<n;k++){
                    if(i==j || j==k || i==k) continue;
                    int num = (digits[i]*100)+(digits[j]*10)+(digits[k]*1);
                    if(num>=100 && num%2==0){
                        st.insert(num);
                    }
                }
            }
        }
        for(auto it: st){
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());

        return ans;
    }
};