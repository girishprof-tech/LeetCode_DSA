class Solution {
public:
    bool valid(string& s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(')
                balance++;
            else if (c == ')') {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> st;
        queue<string> q;
        vector<string> ans;

        q.push(s);
        st.insert(s);

        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (valid(curr)) {
                ans.push_back(curr);
                found = true;
            }

            if (found) continue;

            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] != '(' && curr[i] != ')') continue;

                string next = curr.substr(0, i) + curr.substr(i + 1);

                if (!st.count(next)) {
                    st.insert(next);
                    q.push(next);
                }
            }
        }

        return ans;
    }
};