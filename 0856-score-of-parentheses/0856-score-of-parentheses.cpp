class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int score = 0;
        int depth = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                depth++;
            }
            else {
                depth--;
                if (s[i - 1] == '(') {
                    score += 1 << depth;
                }
            }
        }

        return score;
    }
};