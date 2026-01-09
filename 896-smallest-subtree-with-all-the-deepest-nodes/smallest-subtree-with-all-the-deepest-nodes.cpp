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
public:
    void levelOrder(TreeNode* root, vector<vector<TreeNode*>>& levels,
                    map<TreeNode*, TreeNode*>& mpp) {

        queue<TreeNode*> q;
        q.push(root);
        mpp[root] = NULL;

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> level;

            for (int i = 1; i <= size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node);

                if (node->left) {
                    q.push(node->left);
                    mpp[node->left] = node;
                }
                if (node->right) {
                    q.push(node->right);
                    mpp[node->right] = node;
                }
            }

            levels.push_back(level);
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<vector<TreeNode*>> levels;
        map<TreeNode*, TreeNode*> mpp; // node -> parent
        levelOrder(root, levels, mpp);

        vector<TreeNode*> last = levels.back();
        set<TreeNode*> st(last.begin(), last.end());

        while (st.size() > 1) {
            set<TreeNode*> s;
            for (auto& it : st) {
                s.insert(mpp[it]);
            }
            st = move(s);
        }

        return *st.begin();
    }
};