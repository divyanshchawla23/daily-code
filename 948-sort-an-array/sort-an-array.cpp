class Solution {
public:

    void merge(vector<int>& arr, int n, int low, int mid, int high)
{
    vector<int> ans;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            ans.push_back(arr[left]);
            left++;
        }
        else
        {
            ans.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        ans.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        ans.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = ans[i - low];
    }
}

void merge_sort(vector<int>& arr, int n, int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(arr, n, low, mid);
    merge_sort(arr, n, mid + 1, high);
    merge(arr, n, low, mid, high);
}

    vector<int> sortArray(vector<int>& arr) {
        merge_sort(arr,arr.size(),0,arr.size()-1);
        return arr;
    }
};