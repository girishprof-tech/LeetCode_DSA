class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int> ans;
        int d1 = 0, d2 = 0;

        for (int i = 0; i < n; i++) {
            char ch = seq[i];
            if (ch == '(') {
                if (d1 > d2) {
                    d2++;
                    ans.push_back(1);
                }
                else {
                    d1++;
                    ans.push_back(0);
                }
            }
            else {
                if (d1 > d2) {
                    d1--;
                    ans.push_back(0);
                }
                else {
                    d2--;
                    ans.push_back(1);
                }
            }
        }

        return ans;
    }
};