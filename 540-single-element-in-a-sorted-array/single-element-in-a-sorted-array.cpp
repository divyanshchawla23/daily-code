class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int r = n - 1;

        if (n == 1)
            return nums[0];

        

        while (l <= r) {
            int mid = (l + r) / 2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;

            if (nums[mid] != nums[prev] && nums[mid] != nums[next]) {
                return nums[mid];
            }

            // left half
            if ((mid % 2 == 0 && nums[mid] == nums[next]) ||
                (mid % 2 != 0 && nums[mid] == nums[prev])) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return -1;
    }
};