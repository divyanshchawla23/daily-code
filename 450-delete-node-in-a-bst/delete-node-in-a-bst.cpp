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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        if(root->val == key){ 
        return help(root);
        }


        TreeNode * dummy = root;
        while(root){
            if(root->val>key){
                if(root->left!=NULL && root->left->val ==key){
                    root->left = help(root->left);
                    break;
                }
                else root= root->left;
            }
            else {
                if(root->right!=NULL && root->right->val ==key){
                    root->right = help(root->right);
                    break;
                }
                else root= root->right;

            }
        }
        return dummy;
    }

    TreeNode * help(TreeNode * root){
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;
        TreeNode* rightchild = root->right;
        TreeNode* rightLastchild = findLRight(root->left);
        rightLastchild->right = rightchild;
        return root->left;

    }


    TreeNode * findLRight(TreeNode * root){
        if(root==NULL) return root;
        while(root->right) {root = root->right;}
        return root;
    }
};