class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);
        
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> busy;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> avail;

        for (int i = 0; i < n; i++) {
            avail.push({servers[i], i});
        }

        queue<int> q;
        for (int j = 0; j < m; j++) {
            q.push(j);
        }

        long long time = 0;
        while (!q.empty()) {
            int idx = q.front();
            time = max(time, (long long)idx);

            while (!busy.empty() && busy.top()[0] <= time) {
                avail.push({busy.top()[1], busy.top()[2]});
                busy.pop();
            }

            if (avail.empty()) {
                time = busy.top()[0];
                
                while (!busy.empty() && busy.top()[0] <= time) {
                    avail.push({busy.top()[1], busy.top()[2]});
                    busy.pop();
                }
            }

            pair<int, int> p = avail.top();
            avail.pop();

            busy.push({time + tasks[idx], p.first, p.second});

            ans[idx] = p.second;
            q.pop();
        }

        return ans;
    }
};