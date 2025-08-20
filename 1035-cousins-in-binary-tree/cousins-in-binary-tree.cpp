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
    bool bothFound(int x, int y, vector<pair<int,int>> &v){
        //[ [1,-1],[2,1][3,1],[4,2] ]
        // [2,1][3,1]
        vector<pair<int,int>> check;
        for(auto it:v){
            if(it.first == x){
                check.push_back(it);
            }
            if(it.first == y){
                check.push_back(it);
            }
        }

        if(check.size()<2){
            return false;
        }

        if(check[0].second==check[1].second){
            return false;
        }else return true;
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return false;
        queue<pair<TreeNode*, int>>q;
        vector<vector<pair<int,int>>> ans;

        q.push({root,-1});

        while(!q.empty()){
            int size = q.size();
            vector<pair<int,int>> level;
            for(int i=0;i<size;i++){
                auto it = q.front();
                int val = it.first->val;
                int parent = it.second;
                q.pop();
                level.push_back({val,parent});
                if(it.first->left) q.push({it.first->left,val});
                if(it.first->right) q.push({it.first->right,val});

            }
            ans.push_back(level);
        }
        for(int i =0;i<ans.size();i++){
           
            if(bothFound(x,y,ans[i])){
                return true;
            }
                
            
        }
        return false;
    }
};