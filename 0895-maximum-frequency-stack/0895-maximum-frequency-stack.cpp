class FreqStack {
unordered_map<int, stack<int>> mpp;
unordered_map<int, int> freq;
int most;

public:
    FreqStack() {
        most = 0;
    }
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