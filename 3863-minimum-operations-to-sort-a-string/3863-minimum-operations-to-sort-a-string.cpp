
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (n == 1) return 0;

        int cnt = 0;
        int mn = 0, mx = 0;

        for (int i = 0; i < n; i++) {
            if (s[mn] > s[i]) mn = i;
            if (s[mx] <= s[i]) mx = i;

            if (i > 0 && s[i] < s[i - 1])
                cnt++;
        }

        if (cnt == 0) return 0;
        if (n == 2) return -1;

        if (0 == mn || n - 1 == mx)
            return 1;

        if (0 == mx && n - 1 == mn)
            return cnt == 1 ? 2 : 3;

        return 2;
    }
};
