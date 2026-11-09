class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        vector<int> ans;

        if (n <= k) {
            for (int i = 0; i < n; i++) {
                ans.push_back(i);
            }
            return ans;
        }

        set<int> avail;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> busy;
        vector<int> freq(k, 0);

        for (int i = 0; i < k; i++) {
            avail.insert(i);
        }

        for (int i = 0; i < n; i++) {

            while (!busy.empty() && busy.top().first <= arrival[i]) {
                avail.insert({busy.top().second});
                busy.pop();
            }

            if (avail.empty()) continue;

            int ind = i % k;
            auto it = avail.lower_bound(ind);

            if (it == avail.end()) {
                it = avail.begin();
            }
            
            if (it == avail.end()) continue;

            int server = *it;

            avail.erase(it);
            freq[server]++;
            busy.push({arrival[i] + load[i], server});
        }

        int maxi = *max_element(freq.begin(), freq.end());

        for (int i = 0; i < k; i++) {
            if (freq[i] == maxi) ans.push_back(i);
        }

        return ans;
    }
};