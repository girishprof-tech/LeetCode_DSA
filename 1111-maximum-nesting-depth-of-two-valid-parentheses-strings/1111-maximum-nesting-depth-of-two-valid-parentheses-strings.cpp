class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int> ans;
        int d = 0;

        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                ans.push_back(d % 2);
                d++;
            }
            else {
                d--;
                ans.push_back(d % 2);
            }
        }

        return ans;
    }
};