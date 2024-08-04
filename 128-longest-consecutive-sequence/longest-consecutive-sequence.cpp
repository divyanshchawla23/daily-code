class Solution {
public:
    int longestConsecutive(vector<int>& nums) {


        sort(nums.begin(), nums.end());
        int longest =1 ;
        int cnt = 1;
        int lastsmallest = INT_MIN;

        if (nums.size()==0){
            return 0;
        }

        for (int i=0;i<nums.size();i++){
            if (nums[i]-1 == lastsmallest){
                cnt+=1;
                lastsmallest=nums[i];
            }
            else if(nums[i]!= lastsmallest){
                cnt = 1;
                 lastsmallest=nums[i];

            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};