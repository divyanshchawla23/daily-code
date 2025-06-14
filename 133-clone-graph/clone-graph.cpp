/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(Node* node, Node* cloneNode, map<Node*,Node*> &mpp){

        for(auto it: node->neighbors){

            if(mpp.find(it)==mpp.end()){
                Node* cloneNew = new Node(it->val);
                mpp[it]= cloneNew;
                cloneNode->neighbors.push_back(cloneNew);
                dfs(it,cloneNew,mpp);
            }
            else{
                cloneNode->neighbors.push_back(mpp[it]);
            }

        }

    }
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> mpp;
        if(!node) return NULL;
        Node* cloneNode = new Node(node->val);
        mpp[node]=cloneNode;
        dfs(node,cloneNode,mpp);
        return cloneNode;
    }
};