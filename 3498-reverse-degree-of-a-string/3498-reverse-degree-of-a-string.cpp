class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += ((26 - s[i] + 'a') * (i + 1));
        }

        return ans;
    }
};