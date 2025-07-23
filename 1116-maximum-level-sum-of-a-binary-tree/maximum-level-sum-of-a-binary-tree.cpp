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
    int maxLevelSum(TreeNode* root) {
        vector<vector<int>> levels;
        int maxi = INT_MIN;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int ss = q.size();
            vector<int> level;
            for (int i = 0; i < ss; i++) {
                TreeNode* rt = q.front();
                level.push_back(rt->val);
                q.pop();
                if (rt->left)
                    q.push(rt->left);
                if (rt->right)
                    q.push(rt->right);
            }
            levels.push_back(level);
        }

        for (int i = 0; i < levels.size(); i++) {
            int ans = 0;
            for (auto it : levels[i]) {
                ans += it;
            }
            if (ans > maxi) {
                maxi = ans;
                level = i + 1;
            }
        }
        return level;
    }
};