class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int right =0;
        int left =0;
        int maxlen =0;

        map <int , int > mpp;

        while(right < nums.size()){
            mpp[nums[right]]++;

            if(mpp.size()>2){
                mpp[nums[left]]--;
                if (mpp[nums[left]]==0) mpp.erase(nums[left]);
                left++;
            }

            if (mpp.size()<=2){
                maxlen=max(maxlen,right-left+1);    
            }
            right++;
        }
        return maxlen;
    }
};