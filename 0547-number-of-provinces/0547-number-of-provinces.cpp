class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int n, vector<bool>& visited, int node) {
        if (visited[node]) return;
        visited[node] = true;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && isConnected[node][i]) {
                dfs(isConnected, n, visited, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                dfs(isConnected, n, visited, i);
            }
        }

        return ans;
    }
};