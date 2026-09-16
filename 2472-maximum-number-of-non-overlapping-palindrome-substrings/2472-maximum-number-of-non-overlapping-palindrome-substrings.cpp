class Solution {
public:
    bool isPalindrome(string &s, int i, int j) {
        int left = i;
        int right = j;

        while (left <= right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }

        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.length();

        int l = 0, r = k - 1;
        int cnt = 0;

        while (r < n) {
            if (isPalindrome(s, l, r)) {
                l += k, r += k;
                cnt++;
            }
            else if (isPalindrome(s, l, r+1)) {
                l += k + 1;
                r += k + 1;
                cnt++;
            }
            else {
                l++, r++;
            }
        }

     

        return cnt;
    }
};