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
    TreeNode* help(TreeNode * root , int data){
        if(root==NULL) return new TreeNode(data);

        if(data>root->val) root->right =help(root->right,data);
        else root->left =help(root->left , data) ;

        return root;   
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);

        for(int i =1;i<preorder.size();i++){
           help(root , preorder[i]); 
        }
        return root;
    }
};