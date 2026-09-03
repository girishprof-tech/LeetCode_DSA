class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int minIdx = -1;
        int idx = -1;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (nums1[i] < mn) {
                mn = nums1[i];
                minIdx = i;
            }

            if (idx == -1 && nums1[i] % 2 == 1) idx = i;
        }

        if (mn % 2 == 1 || idx == -1) return true;
        return false;
    }
};