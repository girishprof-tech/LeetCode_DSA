class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        struct Node {
            int cnt, type, color;
            Node(int c, int t, int co) : cnt(c), type(t), color(co) {}
        };

        int n = types.size();

        vector<Node> st;
        st.reserve(n);

        for (int i = 0; i < n; i++) {
            if (st.empty() || types[i] != st.back().type || colors[i] != st.back().color) {
                st.push_back(Node(0, types[i], colors[i]));
            }

            st.back().cnt++;

            if (st.back().cnt == groupSize[st.back().type]) st.pop_back();
        }

        return st.empty();
    }
};