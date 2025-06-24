class Solution {
private:
    void find(int ind, vector<int> &nums, set<int> &st, int n,int k){
        for(int i =0;i<n;i++){
            if(abs(i-ind)<=k){
                st.insert(i);
            }
        }
    }
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int> st;
        for(int i =0;i<n;i++){
            if(nums[i] == key){
                find(i,nums,st,n,k);
            }
        }

        vector<int> ans;

        for(auto it: st){
            ans.push_back(it);
        }

        return ans;

    }
};