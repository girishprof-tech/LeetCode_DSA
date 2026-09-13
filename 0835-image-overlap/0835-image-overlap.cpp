class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        if (n == 1) {
            if (img1[0][0] == 1 && img2[0][0] == 1) return 1;
            else return 0;
        }

        vector<pair<int, int>> a, b;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) a.emplace_back(i, j);
                if (img2[i][j] == 1) b.emplace_back(i, j);
            }
        }
        
        int n1 = a.size();
        int n2 = b.size();
        int ans = 0;
        vector<vector<int>> freq(2 * n, vector<int>(2 * n, 0));

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                int x = b[j].first - a[i].first + n;
                int y = b[j].second - a[i].second + n;

                freq[x][y]++;
                ans = max(ans, freq[x][y]);
            }
        }

        return ans;
    }
};