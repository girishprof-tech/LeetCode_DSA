class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int cnt = 0;
        int mxCnt = 0;
        int start = 0, end = 0;
        unordered_map<char, int> mpp;
        
        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (mpp.find(c) != mpp.end()) {
                start = max(start, mpp[c] + 1);
            }

            end = i;
            mpp[c] = i;
            cnt = end - start + 1;

            mxCnt = max(cnt, mxCnt);
        }

        return mxCnt;
    }
};