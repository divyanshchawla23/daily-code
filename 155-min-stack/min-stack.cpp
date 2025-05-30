class MinStack {
public:
    stack<int> s;
    stack<int> ss;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ss.empty()|| ss.top()>=val){
            ss.push(val);
        }
    }
    
    void pop() {
        int ans = s.top();
        s.pop();
        if(ans == ss.top()){
            ss.pop();
        }
    }
    
    int top() {
        int x = s.top();
        return x;
    }
    
    int getMin() {
        int ans = ss.top();
        return ans;
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