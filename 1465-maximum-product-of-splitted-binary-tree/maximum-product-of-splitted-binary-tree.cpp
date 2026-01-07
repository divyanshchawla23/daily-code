/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int mod = 1e9 + 7;
    long long total_sum = 0;
    long long ans = INT_MIN;

    long long findTotalSum(TreeNode* root) {
        if (!root)
            return 0;
        long long left = findTotalSum(root->left);
        long long right = findTotalSum(root->right);

        long long subSum = left + right + root->val;

        long long s2 = total_sum - subSum;
        ans = max(ans, subSum * s2);


        return subSum;
    }

    int maxProduct(TreeNode* root) {
        total_sum = findTotalSum(root);
        findTotalSum(root);
        return ans%mod;
    }
};