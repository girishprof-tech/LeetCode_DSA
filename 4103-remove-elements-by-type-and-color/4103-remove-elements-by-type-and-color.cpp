class Solution {
public:
    struct Node {
        int cnt, type, color;

        Node(int c, int t, int co) : cnt(c), type(t), color(co) {}
    };

    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        int n = types.size();

        stack<Node> st;
        st.push(Node(0, 0, 0));

        for (int i = 0; i < n; i++) {
            if (types[i] != st.top().type || colors[i] != st.top().color) {
                st.push(Node(0, types[i], colors[i]));
            }

            st.top().cnt++;

            if (st.top().cnt == groupSize[st.top().type]) st.pop();
        }

        if (st.size() == 1) return true;
        return false;
    }
};