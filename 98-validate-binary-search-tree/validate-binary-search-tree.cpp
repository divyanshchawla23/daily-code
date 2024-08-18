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
    bool helper(TreeNode * root , long mini, long maxi){
        if(root==NULL) return true;

        if(root->val >= maxi || root->val <= mini) return false;

        return helper(root->left, mini , root->val)  && helper(root->right, root->val, maxi );
    }
public:
    bool isValidBST(TreeNode* root) {
      return helper(root, LONG_MIN, LONG_MAX) ; 
    }
};