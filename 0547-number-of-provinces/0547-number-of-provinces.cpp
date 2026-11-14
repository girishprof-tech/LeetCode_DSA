class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;

        vector<bool> visited(n, false);
        queue<int> q;

        for (int t = 0; t < n; t++) {
            if (visited[t]) continue;

            ans++;
            q.push(t);
            visited[t] = true;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int i = 0; i < n; i++) {
                    if (!visited[i] && isConnected[node][i]) {
                        visited[i] = true;
                        q.push(i);
                    }
                }
            }
        }
        

        return ans;
    }
};