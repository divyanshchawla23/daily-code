class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node* next;
            Node* prev;

            Node(int key1,int val1){
                key=key1;
                val=val1;
                
            }

    };

    Node* head = new Node(-1,-1);
    Node* tail =  new Node(-1,-1);

    unordered_map<int , Node*> mpp;
    int cap;

    void del(Node* nd){
        Node* p = nd->prev;
        Node* after = nd->next;
        p->next= after;
        after->prev=p;
    }

    void insertAfter(Node* nd){
        Node * curr = head->next;
        head->next = nd;
        nd->prev = head;
        nd->next = curr;
        curr->prev = nd;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()){
            return -1;
        }
        else{
            Node* nd = mpp[key];
            del(nd);
            insertAfter(nd);
            return nd->val;
        }
    }
    
    void put(int key, int value) {

        if(mpp.find(key)!=mpp.end()){
            Node* newNode = mpp[key];
            newNode->val = value;
            del(newNode);
            insertAfter(newNode);
        }

        else{
            if(mpp.size()==cap){
                Node* node = tail->prev;
                mpp.erase(node->key);
                del(node);
            }

            Node* node = new Node(key,value);
            mpp[key]= node;
            insertAfter(node);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */