class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        
        int prevTime = 0;

        for (string log : logs) {
            int j1 = log.find(':');
            int j2 = log.find(':', j1 + 1);

            int id = stoi(log.substr(0, j1));
            char type = log[j1 + 1];
            int time = stoi(log.substr(j2 + 1));

            if (type == 's') {
                if (!st.empty()) {
                    ans[st.top()] += time - prevTime;
                }

                st.push(id);
                prevTime = time;
            }
            else {
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }

        return ans;
    }
};