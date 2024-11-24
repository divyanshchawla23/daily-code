class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;

        int left = 0;
        int right = 0;

        while(left<nums1.size()&&right<nums2.size()){
            if(nums1[left][0]==nums2[right][0]){
                ans.push_back({nums1[left][0],(nums1[left][1]+nums2[right][1])});
                left++;right++;
            }
            else if(nums1[left][0]<nums2[right][0]){
                ans.push_back(nums1[left]);
                left++;
            }
            else{
                ans.push_back(nums2[right]);
                right++;
            }

            
        }

        while (left<nums1.size()){
            ans.push_back(nums1[left++]);
        }
        while (right<nums2.size())ans.push_back(nums2[right++]);
        return ans;

        
        
    }
};