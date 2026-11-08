class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        int n = types.size();

        stack<vector<int>> st;
        st.push({0, 0, 0});

        for (int i = 0; i < n; i++) {
            if (types[i] != st.top()[1] || colors[i] != st.top()[2]) {
                st.push({0, types[i], colors[i]});
            }

            st.top()[0]++;

            if (st.top()[0] == groupSize[st.top()[1]]) {
                st.pop();
            }
        }

        if (st.size() == 1) return true;
        return false;
    }
};