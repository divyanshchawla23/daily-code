class Solution {
public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
         int arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;

    //Insert the elements from the 2 arrays
    // into the 3rd array using left and right
    // pointers:

    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n) {
        arr3[index] = arr1[left];
        index++;
        left++;
    }

    // If left pointer reaches the end:
    while (right < m) {
        arr3[index] = arr2[right];
        index++;
        right++;
    }

    // Fill back the elements from arr3[]
    // to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++) {
            arr1[i] = arr3[i];
        }
}
    
};