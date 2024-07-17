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
    TreeNode * first;
    TreeNode * middle;
    TreeNode * last;
    TreeNode * prev;
public:
    void help(TreeNode* root){
        if(root==NULL) return ;

        help(root->left);
        if(prev->val != INT_MIN && prev->val>root->val){
            if(first == NULL){
                first = prev;
                middle = root;       
            }
            else last = root;
        }

        prev = root;

        help(root->right);
    } 
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        help(root);
        if(first && last) swap(first->val,last->val);
        else if(first && middle) swap(first->val,middle->val);
    }
};