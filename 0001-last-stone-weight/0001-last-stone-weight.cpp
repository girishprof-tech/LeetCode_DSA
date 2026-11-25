class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();

        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            pq.push(stones[i]);
        }

        int top = pq.top();
        while (!pq.empty()) {
            int y = pq.top();
            pq.pop();

            if (pq.empty()) {
                top = y;
                break;
            }

            int x = pq.top();
            pq.pop();

            if (x != y) pq.push(y - x);
            else if (pq.empty()) pq.push(0);
        }

        return top;
    }
};