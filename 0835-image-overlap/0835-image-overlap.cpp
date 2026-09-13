class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int, int>> a;
        vector<pair<int, int>> b;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) a.push_back({i, j});
                if (img2[i][j] == 1) b.push_back({i, j});
            }
        }

        int n1 = a.size();
        int n2 = b.size();

        map<pair<int, int>, int> freq;

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                int x = b[j].first - a[i].first;
                int y = b[j].second - a[i].second;

                freq[{x, y}]++;
            }
        }

        int ans = 0;

        for (pair<pair<int, int>, int> it : freq) {
            ans = max(it.second, ans);
        }

        return ans;
    }
};