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

    TreeNode* help( vector<int>& inorder,int inStart,int inEnd, 
                    vector<int>& postorder,int postStart,int postEnd,
                    map <int , int > &mpp)
    {

        if( inStart > inEnd || postStart > postEnd ) return  NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = mpp[postorder[postEnd]];
        int number = inRoot- inStart;

        root -> left = help(inorder,inStart,inRoot-1,postorder,postStart,postStart+number-1,mpp);


        root -> right  = help(inorder,inRoot+1,inEnd,postorder,postStart+number,postEnd-1,mpp);

        return root;

    }
    
    
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        map <int , int > mpp;

        for(int i =0;i<inorder.size();i++){
            mpp[inorder[i]]= i;
        }

        TreeNode* root = help(inorder,0 ,inorder.size()-1,
                            postorder, 0 , postorder.size()-1 , mpp);


        return root;
        
    }
};