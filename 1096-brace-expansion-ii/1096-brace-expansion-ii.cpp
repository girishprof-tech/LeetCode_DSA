class Solution {
public:
    int i = 0;
    set<string> multiply(set<string> &A, set<string> &B) {
        set<string> ans;
        for (auto& x : A) {
            for (auto& y : B) {
                ans.insert(x + y);
            }
        }
        return ans;
    }
    set<string> parse(string &s) {
        set<string> ans;
        set<string> curr = {""};

        while (i < s.size() && s[i] != '}') {
            if (s[i] == ',') {
                ans.insert(curr.begin(), curr.end());
                curr = {""};
                i++;
            }
            else if (s[i] == '{') {
                i++;
                set<string> temp = parse(s);
                curr = multiply(curr, temp);
            }
            else {
                set<string> temp = {string(1, s[i])};
                curr = multiply(curr, temp);
                i++;
            }
        }

        ans.insert(curr.begin(), curr.end());

        if (i < s.size() && s[i] == '}') i++;

        return ans;

    }
    vector<string> braceExpansionII(string exp) {
        set<string> res = parse(exp);
        return vector<string>(res.begin(), res.end());
    }
};