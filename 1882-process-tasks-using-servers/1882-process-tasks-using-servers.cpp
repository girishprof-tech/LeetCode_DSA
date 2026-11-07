class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busy;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> avail;

        for (int i = 0; i < n; i++) {
            avail.push({servers[i], i});
        }

        long long time = 0;
        for (int j = 0; j < m; j++) {
            time = max(time, (long long)j);

            while (!busy.empty() && busy.top().first <= time) {
                int id = busy.top().second;
                avail.push({servers[id], id});
                busy.pop();
            }

            if (avail.empty()) {
                time = busy.top().first;
                
                while (!busy.empty() && busy.top().first <= time) {
                    int id = busy.top().second;
                    avail.push({servers[id], id});
                    busy.pop();
                }
            }

            auto p = avail.top();
            avail.pop();

            ans[j] = p.second;
            busy.push({time + tasks[j], p.second});
        }

        return ans;
    }
};