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
    TreeNode* builder(vector<int>& preorder,vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd,map<int,int>&mpp){
        if(preStart>preEnd || inStart >inEnd) return NULL;

        TreeNode * root = new TreeNode(preorder[preStart]);

        int indexOfRoot = mpp[preorder[preStart]];
        int nodesLeft = indexOfRoot - inStart;

        root->left = builder(preorder,inorder,preStart+1,preStart+nodesLeft,inStart,indexOfRoot-1,mpp);
        root->right = builder(preorder,inorder,preStart+nodesLeft+1,preEnd,indexOfRoot+1,inEnd,mpp);


        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;

        for(int i =0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        int preStart = 0;
        int preEnd = preorder.size()-1;
        int inStart = 0;
        int inEnd = inorder.size()-1;

        return builder(preorder,inorder,preStart,preEnd,inStart,inEnd,mpp);
    }
};