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
    int check(TreeNode* root, int &maxi){
        if(root == NULL) return 0;

        int lh = max(0,check(root->left,maxi));   // don't consider -ve values
        int rh = max(0,check(root->right,maxi));

        maxi = max(root->val + lh + rh, maxi);

        return max(lh,rh)+root->val;


    }
    int maxPathSum(TreeNode* root) {

        int ans = INT_MIN;
        check(root , ans);

        return ans;


        
    }
};