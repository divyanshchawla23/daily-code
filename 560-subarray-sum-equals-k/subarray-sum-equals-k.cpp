class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum =0;
        int cnt =0;
        
        map<int,int> mpp;
        mpp[0]=1;

        for(int i=0;i<nums.size();i++){
            presum = presum + nums[i];
            int remove = presum -k;
            cnt= cnt+ mpp[remove];
            mpp[presum]= mpp[presum]+1;
        }


        return cnt;

    }
};