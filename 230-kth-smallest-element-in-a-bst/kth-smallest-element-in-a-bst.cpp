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
    void helper(TreeNode* root, int k ,int &cnt,vector<int>&ans){
        if(root==NULL) return ;
        helper(root->left,k ,cnt,ans);
        ans.push_back(root->val);
        helper(root->right,k ,cnt,ans);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        vector<int>ans;
        helper(root,k,cnt,ans);
        return ans[k-1];
    }
};