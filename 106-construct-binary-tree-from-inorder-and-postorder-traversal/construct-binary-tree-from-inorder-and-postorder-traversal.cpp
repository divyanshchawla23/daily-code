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
    TreeNode* builder(vector<int>& postorder,vector<int>& inorder,int postStart,int postEnd,int inStart,int inEnd,map<int,int>&mpp){
        if(postStart>postEnd || inStart >inEnd) return NULL;

        TreeNode * root = new TreeNode(postorder[postEnd]);

        int indexOfRoot = mpp[postorder[postEnd]];
        int nodesLeft = indexOfRoot - inStart;

        root->left = builder(postorder,inorder,postStart,postStart+nodesLeft-1,inStart,indexOfRoot-1,mpp);
        root->right = builder(postorder,inorder,postStart+nodesLeft,postEnd-1,indexOfRoot+1,inEnd,mpp);


        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;

        for(int i =0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        int postStart = 0;
        int postEnd = postorder.size()-1;
        int inStart = 0;
        int inEnd = inorder.size()-1;

        return builder(postorder,inorder,postStart,postEnd,inStart,inEnd,mpp);
    }
};