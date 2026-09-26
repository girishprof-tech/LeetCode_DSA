class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        string ans = "";
        ans.reserve(s.size());

        unordered_map<string, string> mpp;
        mpp.reserve(knowledge.size() * 2 + 1);
        for (int i = 0; i < knowledge.size(); i++) {
            mpp[knowledge[i][0]] = knowledge[i][1];
        }

        bool flag = false;
        string check = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                flag = true;
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