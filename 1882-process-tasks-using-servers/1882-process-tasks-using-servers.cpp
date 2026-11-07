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

        long long time = 0;
        for (int j = 0; j < m; j++) {
            time = max(time, (long long)j);

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

            auto p = avail.top();
            avail.pop();

            ans[j] = p.second;
            busy.push({time + tasks[j], p.first, p.second});
        }

        return ans;
    }
};