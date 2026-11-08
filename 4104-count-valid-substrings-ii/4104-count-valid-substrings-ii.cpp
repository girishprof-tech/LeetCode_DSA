class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();

        vector<int> nexta(n, n);
        vector<int> nextb(n, n);
        vector<int> nextc(n, n);
        int preva = n;
        int prevb = n;
        int prevc = n;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'a') {
                preva = i;
            }
            nexta[i] = preva;

            if (s[i] == 'b') {
                prevb = i;
            }
            nextb[i] = prevb;

            if (s[i] == 'c') {
                prevc = i;
            }
            nextc[i] = prevc;
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int na = nexta[i], nb = n, nc = n;

            if (na < n) {
                nb = nextb[na];
            }

            if (nb < n) {
                nc = nextc[nb];
            }

            if (nc >= n) {
                ans += n - i;
            }
            else {
                ans += nc - i;
            }
        }

        return ans;
    }
};