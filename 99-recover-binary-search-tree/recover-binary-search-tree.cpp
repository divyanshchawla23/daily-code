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
    void recover(TreeNode* root , vector<int>& ans , int &index){
       if(!root) return ;
        recover(root->left,ans,index);
        root->val = ans[index];
        index++;
        recover(root->right,ans,index); 
    }
    void inorder(TreeNode* root , vector<int>& ans){
        if(!root) return ;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);

        sort(ans.begin(),ans.end());

        int index =0;
        //for(int i =0;i<ans.size();i++){
            recover(root , ans , index);
        
    }
};