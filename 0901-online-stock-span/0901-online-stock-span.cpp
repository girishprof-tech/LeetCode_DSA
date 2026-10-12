class StockSpanner {
    stack<pair<int, int>> st;
    int cnt = 0;

public:
    int next(int price) {
        cnt++;
        while (!st.empty() && st.top().first <= price) st.pop();

        int res = st.empty() ? cnt : cnt - st.top().second;

        st.push({price, cnt});

        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */