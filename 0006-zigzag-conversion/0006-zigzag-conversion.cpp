class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;
        
        vector<string> rows(numRows);
        int idx = 0, d = 1;

        for (int i = 0; i < s.size(); i++) {
            rows[idx] += s[i];

            if (idx == 0) d = 1;
            else if (idx == numRows - 1) d = -1;

            idx += d;
        }

        string ans;
        for (string& st : rows) {
            ans += st;
        }

        return ans;
    }
};