class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](const auto& a, const auto& b) { return a[1] < b[1]; });

        int m = queries.size();
        vector<pair<int, int>> v;
        v.reserve(m);

        for (int i = 0; i < m; i++) {
            v.push_back({queries[i], i});
        }
        sort(v.begin(), v.end());

        int l = 0, r = 0;
        int active = 0;

        vector<int> freq(n + 1, 0);
        vector<int> res(m);

        for (int i = 0; i < m; i++) {
            while (r < logs.size() && v[i].first >= logs[r][1]) {
                int id = logs[r][0];

                if (freq[id]++ == 0)
                    active++;

                r++;
            }

            while (l < r && v[i].first - x > logs[l][1]) {
                int id = logs[l][0];

                if (--freq[id] == 0)
                    active--;

                l++;
            }

            res[v[i].second] = n - active;
        }

        return res;
    }
};