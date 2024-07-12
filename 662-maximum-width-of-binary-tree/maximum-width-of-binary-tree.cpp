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
    int widthOfBinaryTree(TreeNode* root) {
      if(root == NULL ) return 0;
      long long  ans = 1;
      queue<pair<TreeNode* , long long>> q ;
      q.push({root,0});

      while(!q.empty()){
        long long size = q.size();
        long long last , first ;
        long long minn= q.front().second;
        for(long long i =0;i<size;i++){
            long long curr = q.front().second - minn;
            TreeNode* divu = q.front().first;
            q.pop();
            if(i==0)  first= curr;
            if(i==size-1)  last= curr;

            if(divu->left!=NULL) q.push({divu->left,(2*curr)});
            if(divu->right!=NULL) q.push({divu->right,(2*curr)+1});

        }
        ans = max(ans , last-first +1);

      }  
      return ans; 
    }
};