class MyStack {
    queue<int> que;

public:
    void push(int x) {
        que.push(x);

        for (int i = 1; i < que.size(); i++) {
            que.push(que.front());
            que.pop();
        }
    }
    
    int pop() {
        int ans = que.front();
        que.pop();
        return ans;
    }
    
    int top() {
        return que.front();
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */