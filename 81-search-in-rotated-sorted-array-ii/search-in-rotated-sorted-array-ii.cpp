class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int minIndex = findMinIndex(nums);
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                minIndex = i + 1; // This will give us the index of the smallest element (or the starting point of the original array)
                break;
            }
        }
        bool part1 = check(nums, target, 0, minIndex - 1); // Check the first part of the array
        bool part2 = check(nums, target, minIndex, nums.size() - 1); // Check the second part of the array
        
        if (!part1 && !part2) {
            return false; // If not available in both parts, return false
        }
        return true;
    }

private:

    int findMinIndex(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If mid element is greater than the last element, the minimum is in the right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Otherwise, it's in the left half including mid
            else if (nums[mid] < nums[high]) {
                high = mid;
            }
            // If elements at mid and high are equal, decrement high to skip duplicates
            else {
                high--;
            }
        }

        return low; // low now points to the minimum element
    }



    bool check(vector<int>& nums, int target, int start, int end) { // Normal binary search logic here
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return true;
            }
            else if (nums[mid] > target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return false;
    }
};