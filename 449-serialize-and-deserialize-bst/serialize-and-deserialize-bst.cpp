/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* nd = q.front();
            q.pop();
            if (!nd) {
                ans += "#,";
            } else {
                ans += to_string(nd->val);
                ans += ",";
            }
            if (nd) {
                q.push(nd->left);
                q.push(nd->right);
            }
        }

        cout << ans;
        cout << "answer ka 0th -> ";
        cout << ans[0];
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(const string& data) {
    if(data.empty()) return nullptr;

    stringstream ss(data);
    string str;
    queue<TreeNode*> q;

    // Read root
    if(!getline(ss, str, ',')) return nullptr;
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); // remove spaces
    if(str.empty() || str == "#") return nullptr;

    TreeNode* root = new TreeNode(stoi(str));
    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        // Left child
        if(getline(ss, str, ',')) {
            str.erase(remove(str.begin(), str.end(), ' '), str.end());
            if(str.empty() || str == "#") {
                node->left = nullptr;
            } else {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }
        }

        // Right child
        if(getline(ss, str, ',')) {
            str.erase(remove(str.begin(), str.end(), ' '), str.end());
            if(str.empty() || str == "#") {
                node->right = nullptr;
            } else {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
    }

    return root;
}

};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;