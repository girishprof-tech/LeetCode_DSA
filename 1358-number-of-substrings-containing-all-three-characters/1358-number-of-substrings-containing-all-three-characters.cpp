class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int ans = 0;
        unordered_map<char, int> mpp;

        int i = 0;

        for (int j = 0; j < n; j++) {
            mpp[s[j]]++;

            while (mpp.size() == 3) {
                ans += n - j;

                if (mpp[s[i]] == 1) mpp.erase(s[i]);
                else mpp[s[i]]--;
                i++;
            }
        }

        return ans;
    }
};