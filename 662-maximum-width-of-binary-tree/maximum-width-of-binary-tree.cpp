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
        unsigned long long ans =0;

        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});

        while(!q.empty()){
            unsigned long long size = q.size();
            unsigned long long left = 0;
            unsigned long long right = 0;
            for(long long i =0;i<size;i++){
                TreeNode* node = q.front().first;
                unsigned long long ind = q.front().second;
                q.pop();
                if(i==0){
                    left = ind;
                }
                if(i==size-1){
                    right = ind;
                }

                if(node->left!=NULL){
                    q.push({node->left,(2*ind)+1});
                }
                if(node->right!=NULL){
                    q.push({node->right,(2*ind)+2});
                }
            }
            ans = max(ans,(right-left+1));
        }

        return ans;
    }
};