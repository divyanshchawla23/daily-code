/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void findParents(TreeNode* root, TreeNode* target,
                map<TreeNode*, TreeNode*>& mpp) {
        queue<TreeNode*> q;
        if(!root) return;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                //  root,parent
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    mpp[node->left] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    mpp[node->right] = node;
                }
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*> mpp;
        findParents(root, target, mpp);
        queue<TreeNode*> q;
        set<TreeNode*> st;
        int level = 0;
        vector<int> ans;

        q.push(target);
        st.insert(target);


        while(!q.empty()){
            int size = q.size();
            if(level==k) break;
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && st.find(node->left)==st.end()) {
                    q.push(node->left);
                    st.insert(node->left);
                }
                if(node->right&&st.find(node->right)==st.end()) {
                    q.push(node->right);
                    st.insert(node->right);
                }
                if(mpp[node] && st.find(mpp[node])==st.end()) {
                    q.push(mpp[node]);
                    st.insert(mpp[node]);
                }
            }
            level++;
        }

        while(!q.empty()){
            TreeNode* nd =q.front();
            ans.push_back(nd->val);
            q.pop();
            
        }
        return ans;


    }
};