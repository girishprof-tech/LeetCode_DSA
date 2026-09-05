class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int mx = 0;
        int l = 0;
        unordered_set<char> st;
        
        for (int r = 0; r < n; r++) {
            while (st.find(s[r]) != st.end()) {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            int len = r - l + 1;
            mx = max(len, mx);
        }

        return mx;
    }
};