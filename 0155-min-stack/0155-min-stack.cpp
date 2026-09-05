class MinStack {
    stack<int> st;
    stack<int> temp;
public:
    void push(int value) {
        st.push(value);
        if (temp.empty() || value <= temp.top()) temp.push(value);
    }
    
    void pop() {
        if (temp.top() == st.top()) temp.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return temp.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */