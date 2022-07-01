class MinStack {
public:
    stack<int> s,mn;
    MinStack() {
        
    }
    void push(int val) {
        s.push(val);
        if(mn.empty() or val<=mn.top())
            mn.push(val);
    }
    void pop() {
        if(s.top()==mn.top())
            mn.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mn.top();
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