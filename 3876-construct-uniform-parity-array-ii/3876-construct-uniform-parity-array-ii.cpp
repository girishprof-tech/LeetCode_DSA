class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int idx = -1;
        int mn = INT_MAX;
        for (int i = 0; i < n; i++) {
            mn = min(mn, nums1[i]);

            if (idx == -1 && nums1[i] % 2 == 1)
                idx = 0;
        }

        if (mn % 2 == 1 || idx == -1)
            return true;
        return false;
    }
};