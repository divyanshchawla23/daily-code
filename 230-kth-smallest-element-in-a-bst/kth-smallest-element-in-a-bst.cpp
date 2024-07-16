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
    void help(TreeNode* root , int  &k, int &cnt , int &res){
        if(root==NULL) return ;
        help(root->left, k , cnt , res);
        cnt++;
        if(cnt ==k)  res =root->val ;
        help(root->right, k , cnt , res);


    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt =0;
        int res=-1;
        help(root , k , cnt , res);
        return res;
    }
};