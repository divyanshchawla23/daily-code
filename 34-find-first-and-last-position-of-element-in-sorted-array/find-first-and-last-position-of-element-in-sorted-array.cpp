class Solution {

private:
    int bs(vector<int> nums, int target, int isFirst) {
        int low = 0;
        int high = nums.size() - 1;

        int ans = -1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if(isFirst)high = mid - 1;
                else low = mid+1;
            } else if (nums[mid] < target) {
                low = low + 1;
            } else
                high = mid - 1;
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int first = bs(nums, target, 1);
        int second = bs(nums, target, 0);

        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};