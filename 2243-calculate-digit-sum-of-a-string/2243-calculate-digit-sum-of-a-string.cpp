class Solution {
public:
    string digitSum(string s, int k) {
        string temp = "";
        int sum = 0;

        while (s.size() > k) {

            for (int i = 0; i < s.size(); i++) {
                sum += s[i] - '0';

                if ((i + 1) % k == 0 || i == s.size() - 1) {
                    temp += to_string(sum);
                    sum = 0;
                }
            }

            s = temp;
            temp = "";
        }

        return s;
    }
};