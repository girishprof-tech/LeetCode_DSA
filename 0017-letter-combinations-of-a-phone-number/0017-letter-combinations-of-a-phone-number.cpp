class Solution {
public:
    void func(string &digits, vector<string> &ans, string s, int ind, vector<vector<char>> &mpp) {
        if (s.length() == digits.length()) {
            ans.push_back(s);
            return;
        }
        vector<char> vec = mpp[digits[ind] - '0'];
        for (int i = 0; i < vec.size(); i++) {
            char ch = vec[i];
            func(digits, ans, s + ch, ind + 1, mpp);
        }
    }
    vector<string> letterCombinations(string &digits) {
        vector<vector<char>> mpp(10);

        char ch = 'a';
        
        for (int i = 0; i <= 9; i++) {
            if (i == 0 || i == 1) {
                mpp[i] = {};
                continue;
            }
            int end = 3;
            if (i == 7 || i == 9) {
                end = 4;
            }

            vector<char> temp;
            for (int j = 0; j < end; j++) {
                temp.push_back(ch);
                ch++;
            }

            mpp[i] = temp;
        }

        vector<string> ans;
        string s = "";
        func(digits, ans, s, 0, mpp);
        return ans;
    }
};