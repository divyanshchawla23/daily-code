class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for(int i = n-1 ;i>=0;i--){
            if(st.find(nums[i])!=st.end()){
                return ceil((i+1)/3.0);
            }
            st.insert(nums[i]);
        }

        return 0;
    }
};