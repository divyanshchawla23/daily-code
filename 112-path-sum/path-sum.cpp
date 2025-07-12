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
private:
    bool helper(TreeNode* root, int targetSum){
        if(!root) return false;

        if (!root->left && !root->right) {
            return root->val == targetSum;
        }

        if(helper(root->left,targetSum-(root->val))
        ||helper(root->right,targetSum-(root->val))) return true;
        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return helper(root,targetSum);

    }
};