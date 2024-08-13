class LRUCache {
public:
    class Node{
        public:
        int val;
        int key;
        Node * next ;
        Node * prev;

        Node(int key1 , int value1){
            key = key1;
            val = value1;

        }
    };

        Node * head = new Node(-1,-1);
        Node * tail = new Node(-1,-1);

        map<int , Node*> mpp;
        int cap;
        
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail-> prev = head;
        
    }

    void deletekkaw(Node * head){
        Node * back = head -> prev;
        Node * fwd = head->next;

        back -> next = fwd;
        fwd -> prev = back;
      
    }

    void insertAfter(Node * temp){
        Node * afterHead = head->next;
        
        temp->next = afterHead;
        afterHead->prev = temp;
        
        
        head->next= temp;
        temp->prev = head;

    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* nd = mpp[key];
            deletekkaw(nd);
            insertAfter(nd);

            return nd->val;
        }

        return -1;

    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node * temp =mpp[key];
            temp -> val = value;
            deletekkaw(temp);
            insertAfter(temp);
        }

        else{
            if(mpp.size()== cap){
                mpp.erase(tail->prev->key);   // least recently used
                deletekkaw(tail->prev);
            }
            Node* newNode = new Node(key, value);
            insertAfter(newNode);
            mpp[key]= newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */