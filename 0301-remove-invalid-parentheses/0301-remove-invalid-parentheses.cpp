class Solution {
public:
    bool valid(string& curr) {
        int n = curr.length();
        int ko = 0;
        int kc = 0;

        for (int i = 0; i < n; i++) {
            if (curr[i] == '(') ko++;
            else if (curr[i] == ')') {
                if (ko == 0) kc++;
                else ko--;
            }
        }

        if (ko + kc == 0) return true;
        return false;
    }
    void recr(unordered_set<string>& st, string &s, string& curr, int removed, int kc, int i) {
        if (i == s.size()) {
            if (curr.size() == s.size() - kc) {
                if (valid(curr)) st.insert(curr);
            }
            return;
        }

        if (removed > kc) {
            if (curr.size() == s.size() - kc) {
                if (valid(curr)) st.insert(curr);
            }
            return;
        }
        
        curr += s[i];
        recr(st, s, curr, removed, kc, i + 1);
        curr.pop_back();

        if (s[i] == '(' || s[i] == ')') {
            recr(st, s, curr, removed + 1, kc, i + 1);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> st;
        int n = s.length();
        int ko = 0;
        int kc = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') ko++;
            else if (s[i] == ')') {
                if (ko == 0) kc++;
                else ko--;
            }
        }

        kc += ko;

        if (kc == 0) {
            return {s};
        }

        if (kc == s.size()) {
            return {""};
        }

        string curr = "";
        recr(st, s, curr, 0, kc, 0);

        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};