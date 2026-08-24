class Solution {
public:
    void func(vector<string>& ans, string path, int start, int target, long long value, long long last, string& num) {
        if (start == num.size()) {
            if (value == target) ans.push_back(path);
            return;
        }

        string temp = "";
        long long curr = 0;

        for (int i = start; i < num.size(); i++) {
            if (i > start && num[start] == '0') break;

            temp += num[i];
            curr = curr * 10 + (num[i] - '0');

            if (start == 0) {
                func(ans, temp, i + 1, target, curr, curr, num);
            }
            else {
                func(ans, path + '+' + temp, i + 1, target, value + curr, curr, num);

                func(ans, path + '-' + temp, i + 1, target, value - curr, -curr, num);

                func(ans, path + '*' + temp, i + 1, target, value - last + last * curr, last * curr, num);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        func(ans, "", 0, target, 0, 0, num);
        return ans;
    }
};