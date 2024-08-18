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
    void helper(TreeNode* root, int &k, int &res, int &cnt)
    {
      
        if(root==NULL) return ;

        helper(root->left, k, res,cnt);
        cnt++;
        if(cnt ==k) res = root ->val;
        helper(root->right, k, res,cnt);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        int cnt =0;
        helper(root, k , res,cnt);
        return res;
    }
};