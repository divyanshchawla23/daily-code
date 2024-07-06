class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        
        map<int , int >mpp;
        int cnt=0;
        int presum=0;
        mpp[0]=1;

        for(int i=0;i<nums.size();i++){
            presum = presum +nums[i];
            int remove = presum -k;
            cnt = cnt +mpp[remove];
            mpp[presum]= mpp[presum]+1;

        }


        return cnt;
    }
};
    