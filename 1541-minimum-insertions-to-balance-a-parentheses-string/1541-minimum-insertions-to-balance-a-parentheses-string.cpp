class Solution {
public:
    int minInsertions(string s) {
        // int ans = 0;
        // int cnt = 0;

        // for (int i = 0; i < s.length(); i++) {
        //     if (s[i] == '(') {
        //         cnt++;
        //     }
        //     else if (cnt == 0 && s[i + 1] == ')') {
        //         ans++;
        //         i++;
        //     }
        //     else if (cnt == 0) {
        //         ans += 2;
        //     }
        //     else if (s[i + 1] != ')') {
        //         ans++;
        //         cnt--;
        //     }
        //     else {
        //         cnt--;
        //         i++;
        //     }
        // }

        // return ans + 2 * cnt;

        int res = 0, t = 0;
        for(char c: s) {
            if(c == '(') {
                if(t % 2) res++,t++;
                else t+= 2;
            }
            else if(t == 0) res++, t = 1;
            else t--;
        }
        return res + t;
    }
};