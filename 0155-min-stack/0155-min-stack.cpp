class MinStack {
    stack<long long> st;
    int mini;

public:
    void push(int value) {
        if (st.empty()) {
            st.push(value);
            mini = value;
            return;
        }

        if (value < mini) {
            st.push(2 * (long long)value - mini);
            mini = value;
        }
        else {
            st.push(value);
        }
    }
    
    void pop() {
        if (st.top() < mini) {
            mini = 2 * (long long)mini - st.top();
            st.pop();
        }
        else st.pop();
    }
    
    int top() {
        if (st.top() < mini) return mini;
        else return st.top();
    }
    
    int getMin() {
        return mini;
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