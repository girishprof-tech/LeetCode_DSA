class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int cnt = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                cnt += 2;
            }
            else {
                if (cnt == 0 && s[i + 1] == ')') {
                    ans++;
                    i++;
                }
                else if (cnt == 0) {
                    ans += 2;
                }
                else if (s[i + 1] != ')') {
                    ans++;
                    cnt -= 2;
                }
                else {
                    cnt -= 2;
                    i++;
                }
            }
        }

        ans += cnt;
        return ans;
    }
};