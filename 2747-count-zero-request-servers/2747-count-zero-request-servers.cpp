class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        unordered_map<int, int> mpp;
        for (int i = 0; i < queries.size(); i++) {
            mpp[queries[i]] = i;
        }

        sort(queries.begin(), queries.end());

        int l = 0, r = 0;
        unordered_map<int, int> freq;
        vector<int> res(queries.size());

        for (int i = 0; i < queries.size(); i++) {
            while (l < logs.size() && queries[i] - x > logs[l][1]) {
                int id = logs[l][0];
                
                if (freq.find(id) != freq.end()) {
                    if (freq[id] == 1) freq.erase(id);
                    else freq[id]--;
                }

                l++;
                if (r < l) r = l;
            }

            while (r < logs.size() && queries[i] >= logs[r][1]) {
                freq[logs[r][0]]++;
                r++;
            }

            res[mpp[queries[i]]] = n - freq.size();
        }

        return res;
    }
};