class FreqStack {
unordered_map<int, stack<int>> mpp;
unordered_map<int, int> freq;
int most = 0;

public:
    void push(int val) {
        freq[val]++;
        mpp[freq[val]].push(val);
        most = max(most, freq[val]);
    }
    
    int pop() {
        int res = mpp[most].top();
        freq[res]--;
        mpp[most].pop();
        if (mpp[most].empty()) most--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */