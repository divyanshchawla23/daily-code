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
        if(!root) return ans;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* nd = q.front();
                q.pop();
                if(nd==NULL){ 
                    ans+='$';
                    ans+=',';
                }
                else ans+= to_string(nd->val)+',';
                
                if(nd!=NULL){
                    q.push(nd->left);
                    q.push(nd->right);
                }
            }
        }
        cout << ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* newNode = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(newNode);
        while(!q.empty()){
            TreeNode* nd = q.front();
            q.pop();
            getline(s,str,',');
            if(str=="$"){
                nd->left=NULL;
            }else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                nd->left = leftNode;
                q.push(leftNode);
            }
            getline(s,str,',');
            if(str=="$"){
                nd->right=NULL;
            }else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                nd->right = rightNode;
                q.push(rightNode);
            }
        }
        return newNode;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));