class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();

        int a = -1, b = -1, c = -1;
        long long res = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') a = i;
            else if (s[i] == 'b') b = a;
            else c = b;

            res += i - c;
        }

        return res;
    }
};