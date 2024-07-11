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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root == NULL) return ans;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> help;
            for(int i =0;i<size;i++){

                TreeNode* div = q.front();
                q.pop();


            if(div->left != NULL) q.push(div->left);
            if(div->right != NULL) q.push(div->right);
            help.push_back(div->val);
            }
            
            ans.push_back(help);
            

        }
        for(int i =0;i<ans.size();i++){
            if(i%2!=0){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
        


    }
};