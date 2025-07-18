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
    TreeNode* findParents(TreeNode* root, int start,
    map<TreeNode*, TreeNode*>& mpp) {
        TreeNode* res = NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                if(node->val==start) res= node;
                q.pop();
                if(node->left){ 
                    q.push(node->left);
                    mpp[node->left] = node;
                }
                if(node->right){ 
                    q.push(node->right);
                    mpp[node->right] = node;
                }
            }
        }

        return res;
    }
    

    int bleed(TreeNode* root, TreeNode* startRoot,map<TreeNode*,TreeNode*>& mpp,int& timer) {

        queue<TreeNode*>q;
        set<TreeNode*> st;
        q.push(startRoot);
        st.insert(startRoot);
        while(!q.empty()){
            int fg = 0; 
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left && st.find(node->left)==st.end()){ 
                    q.push(node->left);
                    st.insert(node->left);
                    fg =1;
                }
                if(node->right && st.find(node->right)==st.end()){ 
                    q.push(node->right);
                    st.insert(node->right);
                    fg =1;
                }
                if(mpp[node] && st.find(mpp[node])==st.end()){
                    q.push(mpp[node]);
                    st.insert(mpp[node]);
                    fg =1;
                }
            }
            if(fg) timer++;
        }

        return timer;
    }



public:
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mpp;
        TreeNode* startRoot = findParents(root, start, mpp);
        int timer =0;
        return bleed(root, startRoot, mpp, timer);

    }
};