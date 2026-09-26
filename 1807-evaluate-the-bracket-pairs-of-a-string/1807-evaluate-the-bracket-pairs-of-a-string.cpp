class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        string ans = "";

        unordered_map<string, string> mpp;
        for (int i = 0; i < knowledge.size(); i++) {
            mpp[knowledge[i][0]] = knowledge[i][1];
        }

        bool flag = false;
        string check = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                flag = true;
                continue;
            }
            else if (s[i] == ')') {
                flag = 0;

                if (mpp.find(check) != mpp.end()) {
                    ans += mpp[check];
                }
                else ans += '?';
                
                check = "";
            }
            else if (flag) {
                check += s[i];
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }
};