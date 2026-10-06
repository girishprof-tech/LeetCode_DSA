class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int ans = 0;

        int a = -1, b = -1, c = -1;

        int i = 0;

        for (int j = 0; j < n; j++) {
            if (s[j] == 'a') a = j;
            else if (s[j] == 'b') b = j;
            else c = j;

            int mn = min(a, min(b, c));

            if (mn != -1) {
                ans += mn + 1;
            }
        }

        return ans;
    }
};