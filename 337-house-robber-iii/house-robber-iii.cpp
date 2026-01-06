/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,int> dp;
    int helper(TreeNode* root){
        if(!root) return 0;
        if(dp.find(root)!=dp.end()){
            return dp[root];
        }

        int take = root -> val;

        if(root->left)
            take += helper(root->left->left) + helper(root->left->right);

        if(root->right)
            take += helper(root->right->left) + helper(root->right->right);

        int skip = helper(root->left) + helper(root->right);

        return dp[root] = max(take,skip);
    }
    int rob(TreeNode* root) {
        return helper(root);
    }
};