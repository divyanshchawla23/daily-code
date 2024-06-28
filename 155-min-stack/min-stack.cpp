class MinStack {
public:

    long long el = INT_MAX;

    stack<long long > s;
    MinStack() {

        el = INT_MAX;
        
    }
    
    void push(int val) {
        if(s.size()==0){
            s.push(val);
            el = val;
        }
        else{
            if(val>=el){
                s.push(val);
            }
            else{
                s.push(2LL *val - el);
                el = val;
            }

        }
        
    }
    
    void pop() {
        

        if(s.top()>= el){
            s.pop();
        }
        else if(s.top()<el){
            el = 2LL * el - s.top() ;
            s.pop();
        }
        
    }
    
    int top() {
        if(s.size()==0) return -1;

        if(s.top()>=el) return s.top();

        else
        {
            return el;
        }
    }
    
    int getMin() {
        if(s.size()==0) return -1;

        return el;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */