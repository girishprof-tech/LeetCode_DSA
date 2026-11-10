class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dist(n + 1, INT_MAX);
        set<pair<int, int>> st;
        
        dist[0] = 0;
        st.insert({0, 0});

        while (!st.empty()) {
            pair<int, int> top = *st.begin();
            st.erase(st.begin());

            int d = top.first, u = top.second;

            if (u == n) return d;

            for (int v = u + 1; v <= min(n, u + 3); v++) {
                int dis = d + costs[v - 1] + (v - u) * (v - u);

                if (dis < dist[v]) {
                    st.erase({dist[v], v});
                    dist[v] = dis;
                    st.insert({dist[v], v});
                }
            }
        }

        return dist[n];
    }
};