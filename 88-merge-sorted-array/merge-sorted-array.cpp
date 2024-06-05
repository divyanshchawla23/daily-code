class Solution {
public:
    void swapIfGreater(vector<int>& nums1, vector<int>& nums2, int n, int m) {
        // Swap if the element in nums1 is greater than the element in nums2
        if (nums1[n] > nums2[m]) {
            swap(nums1[n], nums2[m]);
        }
    }

    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        // Resize nums1 to fit both arrays
        nums1.resize(n + m);
        for (int i = n; i < n + m; ++i) {
            nums1[i] = nums2[i - n];
        }

        // Use the gap method to sort the combined array
        int len = n + m;
        int gap = (len / 2) + (len % 2);

        while (gap > 0) {
            int left = 0;
            int right = left + gap;

            while (right < len) {
                if (right < n) {
                    // Both pointers in nums1
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                } else if (left < n) {
                    // left in nums1, right in nums2 (actually in the combined nums1)
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                } else {
                    // Both pointers in nums2 (actually in the combined nums1)
                    if (nums1[left] > nums1[right]) {
                        swap(nums1[left], nums1[right]);
                    }
                }
                left++;
                right++;
            }

            if (gap == 1) {
                break;
            }
            gap = (gap / 2) + (gap % 2);
        }
    }
};
