class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;

        unordered_set<int> st;

        while (true) {
            if (st.size() == n) break;

            for (int i = 0; i < n; i++) {
                if (st.count(i)) continue;

                ans++;
                st.insert(i);
                queue<int> q;

                for (int j = 0; j < n; j++) {
                    if (isConnected[i][j] && i != j) {
                        q.push(j);
                        st.insert(j);
                    }
                }

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < n; j++) {
                        if (st.count(j)) continue;

                        if (isConnected[node][j]) {
                            q.push(j);
                            st.insert(j);
                        }
                    }
                }
            }
        }

        return ans;
    }
};