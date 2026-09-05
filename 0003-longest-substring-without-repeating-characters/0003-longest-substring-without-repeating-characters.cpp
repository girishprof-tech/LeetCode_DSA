class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int mx = 0;
        vector<int> hash(128, -1);
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (hash[s[right]] >= left) {
                left = hash[s[right]] + 1;
            }

            hash[s[right]] = right;
            mx = max(mx, right - left + 1);
        }
    
        return mx;
    }
};