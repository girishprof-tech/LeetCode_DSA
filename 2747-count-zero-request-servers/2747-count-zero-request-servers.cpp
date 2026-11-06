class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int size = queries.size();
        vector<int> res(size, 0);

        sort(logs.begin(), logs.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        unordered_map<int, int> mpp;
        for (int i = 0; i < size; i++) {
            mpp[queries[i]] = i;
        }

        sort(queries.begin(), queries.end());

        int l = 0, r = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < size; i++) {
            while (l < logs.size() && queries[i] - x > logs[l][1]) {
                if (freq.find(logs[l][0]) != freq.end()) {
                    if (freq[logs[l][0]] == 1) freq.erase(logs[l][0]);
                    else freq[logs[l][0]]--;
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