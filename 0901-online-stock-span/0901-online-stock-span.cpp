class StockSpanner {
    stack<pair<int, int>> st;
    int cnt;

public:
    StockSpanner() {
        cnt = 0;
    }

    int next(int price) {
        cnt++;
        while (!st.empty() && st.top().first <= price) st.pop();

        int res;
        if (st.empty()) res = cnt;
        else res = cnt - st.top().second;

        st.push({price, cnt});

        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */