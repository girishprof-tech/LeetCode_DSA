class FreqStack {
unordered_map<int, stack<int>> mpp;
unordered_map<int, int> freq;
int most = 0;

public:
    void push(int val) {
        most = max(most, ++freq[val]);
        mpp[freq[val]].push(val);
    }
    
    int pop() {
        int res = mpp[most].top();
        mpp[most].pop();
        if (!mpp[freq[res]--].size()) most--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */