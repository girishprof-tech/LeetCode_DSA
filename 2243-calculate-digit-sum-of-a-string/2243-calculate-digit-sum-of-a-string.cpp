class Solution {
public:
    string digitSum(string s, int k) {
        int sum = 0;

        while (s.size() > k) {
            string temp = "";
            
            for (int i = 0; i < s.size(); i++) {
                sum += s[i] - '0';

                if ((i + 1) % k == 0 || i == s.size() - 1) {
                    temp += to_string(sum);
                    sum = 0;
                }
            }

            s = temp;
        }

        return s;
    }
};