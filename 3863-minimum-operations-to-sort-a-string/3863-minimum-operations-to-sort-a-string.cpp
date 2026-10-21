class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        if (n == 1) return 0;
        if (n == 2) {
            if (s[0] > s[1]) return -1;
            return 0;
        }

        int cnt = 0;
        int mx = 0, mn = 0;

        for (int i = 0; i < n; i++) {
            if (i < n - 1 && s[i] > s[i + 1]) cnt++;

            if (s[mx] <= s[i]) mx = i;
            if (s[mn] > s[i]) mn = i;
        }

        if (cnt == 0) return 0;
        if (mx == 0 && mn == n - 1 && cnt == 1) return 2;
        if (mx == 0 && mn == n - 1) return 3;
        if (mn == 0 || mx == n - 1) return 1;
        return 2;
    }
};