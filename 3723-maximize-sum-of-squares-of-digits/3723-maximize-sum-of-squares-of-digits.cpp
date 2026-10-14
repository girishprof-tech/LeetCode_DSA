class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string res = "";

        for (int i = 0; i < num; i++) {
            int digit = 0;
            if (sum >= 9) digit = 9;
            else digit = sum % 10;
            
            res += to_string(digit);

            sum -= digit;
        }

        return res;
    }
};