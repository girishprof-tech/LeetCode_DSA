class Solution {
public:
    bool checkForEven(vector<int>& nums1) {
        int n = nums1.size();
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 1) {
                idx = i;
                break;
            }
        }

        if (idx == -1) return true;
        return false;
    }

    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(), nums1.end());

        if (nums1[0] % 2 == 0)
            return checkForEven(nums1);

        return true;
    }
};