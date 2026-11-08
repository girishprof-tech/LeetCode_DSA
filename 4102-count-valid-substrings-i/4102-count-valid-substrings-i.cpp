class Solution {
public:
    long long countValidSubstrings(string s) {
        int n = s.size();
        
        long long ans = 0;
        int ind = -1;
        
        for (int i = 0; i < n; i++) {
            if (i > 1 && s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a') {
                ind = i - 2;
            }

            ans += i - 1LL * ind;
        }

        return ans;
    }
};