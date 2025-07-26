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
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        map<int, int>& mpp) {
        if (preStart > preEnd || inEnd < inStart)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int indexOfRoot = mpp[preorder[preStart]];
        int nodesLeft = indexOfRoot - inStart;

        root->left =
            buildTree(preorder, preStart+1, preStart+nodesLeft, inorder, inStart, indexOfRoot-1, mpp);
        root->right =
            buildTree(preorder, preStart+nodesLeft+1, preEnd, inorder, indexOfRoot+1, inEnd, mpp);

                return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        map<int, int> mpp;
        int inStart = 0;
        int inEnd = inorder.size() - 1;
        int preEnd = preorder.size() - 1;
        int preStart = 0;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        TreeNode* root =
            buildTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mpp);
        return root;
    }
};