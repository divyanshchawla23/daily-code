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
    long long kthLargestLevelSum(TreeNode* root, int k) {

          if (!root) return -1;  
       queue<TreeNode*>q;
        vector<long long > v;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
        
            long long lvlSum =0;

            for(int i =1;i<=size;i++){
                TreeNode * nd = q.front();
                q.pop();
                lvlSum+= nd->val;
                if(nd->left) q.push(nd->left);
                if(nd->right) q.push(nd->right);
            }

            v.push_back(lvlSum);
        }

        priority_queue<long long, vector<long long> , greater<long long>> pq;


        if(v.size()<k) return -1;


        for(auto it: v){
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();

        

        

        
    }
};