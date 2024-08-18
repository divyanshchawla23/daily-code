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
    void helper(TreeNode* root, int &k, int &res, vector<int> &ans)
    {
        if(root==NULL) return ;
        helper(root->left, k, res,ans);
        ans.push_back(root -> val);
        helper(root->right, k, res,ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = -1;
        vector<int> ans;
        helper(root, k , res,ans);

        int x = ans[k-1];
        return x;
        
    }
};