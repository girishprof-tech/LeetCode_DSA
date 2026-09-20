class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        vector<string> ans;

        int stream = 1;
        stack<int> st;

        for (int i = 0; i < m; i++) {
            while (stream != target[i]) {
                ans.push_back("Push");
                ans.push_back("Pop");
                stream++;
            }

            stream++;
            ans.push_back("Push");
        }

        return ans;
    }
};