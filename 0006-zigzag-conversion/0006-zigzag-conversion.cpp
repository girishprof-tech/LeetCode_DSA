class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows >= n || numRows == 1) return s;
        
        vector<vector<char>> rows(numRows);
        int idx = 0, d = 1;
        
        for (char ch : s) {
            rows[idx].push_back(ch);
            
            if (idx == 0) d = 1;
            else if (idx == numRows - 1) d = -1;
        
            idx += d;
        }
        
        string ans;
        for (vector<char> row : rows) {
            for (char ch : row) {
                ans += ch;
            }
        }

        return ans;
    }
};