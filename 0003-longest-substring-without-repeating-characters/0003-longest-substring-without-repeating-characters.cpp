class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int mx = 0;
        vector<int> hash(128, -1);
        int l = 0, r = 0;
        
        while (r < n) {
            if (hash[s[r]] != -1) {
                if (hash[s[r]] >= l) {
                    l = hash[s[r]] + 1;
                }
            }
            
            int len = r - l + 1;
            hash[s[r]] = r;
            r++;
            mx = max(mx, len);
        }
    
        return mx;
    }
};