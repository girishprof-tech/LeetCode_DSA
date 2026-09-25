class Solution {
public:
    set<string> ans;
    void dfs(string s) {
        int r = s.find('}');

        if (r == string::npos) {
            ans.insert(s);
            return;
        }

        int l = s.rfind('{', r);

        string left = s.substr(0, l);
        string mid = s.substr(l + 1, r - l - 1);
        string right = s.substr(r + 1);

        string part;
        stringstream ss(mid);

        while(getline(ss, part, ',')) {
            dfs(left + part + right);
        }
    }
    vector<string> braceExpansionII(string exp) {
        dfs(exp);
        return vector<string>(ans.begin(), ans.end());
    }
};