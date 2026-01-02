class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        int ans = 0;

        for(int i = n-1;i>=0;i--){
            if(st.find(nums[i])!=st.end()){
                int len = i+1;
                return ceil((double)len/3);
            }
            st.insert(nums[i]);
        }
        return 0;
    }
};