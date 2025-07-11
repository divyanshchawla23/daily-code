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
    void helper(TreeNode* root,vector<int>&ans, set<int>&st, int level){
        if(root==NULL) return;

        if(st.find(level)==st.end()){
            ans.push_back(root->val);
            st.insert(level);
        }

        helper(root->right,ans,st,level+1);
        helper(root->left,ans,st,level+1);

    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        set<int> st;

        helper(root,ans,st,0);

        return ans;
    }
};