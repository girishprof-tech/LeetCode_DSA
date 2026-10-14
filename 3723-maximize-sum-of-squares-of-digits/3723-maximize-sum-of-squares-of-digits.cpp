class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string res = "";
        
        if (sum <= 9) {
            res += to_string(sum);
            for (int i = 1; i < num; i++) res += "0";
            return res;
        }

        for (int i = 0; i < num; i++) {
            int digit = 0;
            if (sum >= 9) digit = 9;
            else digit = sum % 10;
            
            res += to_string(digit);

            sum -= digit;
        }

        if (sum == 0) return res;

        return "";
    }
};