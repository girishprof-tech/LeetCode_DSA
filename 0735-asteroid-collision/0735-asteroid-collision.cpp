class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && asteroids[i] < 0 && st.top() > 0 &&
                   abs(asteroids[i]) > st.top())
                st.pop();

            if (!st.empty() && asteroids[i] < 0 &&
                st.top() == abs(asteroids[i])) {
                st.pop();
                continue;
            }

            if (st.empty() || asteroids[i] > 0 || st.top() < 0)
                st.push(asteroids[i]);
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};