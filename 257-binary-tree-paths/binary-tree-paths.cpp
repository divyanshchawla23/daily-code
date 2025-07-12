/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void helper(TreeNode* root, vector<string>& ans, string s) {
        s += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(s);
            return;
        }
        s += "->";
        if (root->left)
            helper(root->left, ans, s);
        if (root->right)
            helper(root->right, ans, s);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (!root)
            return ans;
        string s = "";
        helper(root, ans, s);
        return ans;
    }
};