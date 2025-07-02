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
    void helper(TreeNode* root,set<int> &st,vector<int> &ans,int level){
        if(root==NULL) return;

        if(st.find(level)==st.end()){
            ans.push_back(root->val);
            st.insert(level);
        }

        helper(root->right,st,ans,level+1);
        helper(root->left,st,ans,level+1);


    }
public:
    vector<int> rightSideView(TreeNode* root) {
        // {node->val,level}
        set<int> st;
        vector<int> ans;
        int level =0;

        if(root==NULL) return ans;

        helper(root,st,ans,level);

        return ans;

    }
};