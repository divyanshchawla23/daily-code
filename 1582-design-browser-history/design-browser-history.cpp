// create a doubly linked list of strings
class ListNode1{
    public:
      string data;
      ListNode1* next;
      ListNode1* back;

    ListNode1(string url){
        this->data = url;
        this->next = NULL;
        this->back = NULL;
    }
};

// solution function
class BrowserHistory {
public:
    ListNode1* current;
    

    BrowserHistory(string homepage) {
        current = new ListNode1(homepage);
        
    }
    
    void visit(string url) {
        ListNode1* newNode = new ListNode1(url);
        newNode -> back =current;
        current ->next = newNode;
        current = current -> next;
        
    }
    
    string back(int steps) {
        while(steps){
            if(current->back)current = current -> back;
            steps--;
        }
        return current -> data;
    }
    
    string forward(int steps) {
        while(steps){
            if(current->next)current = current -> next;
            steps--;
        }
        return current -> data;
    }
};