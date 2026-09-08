class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans(n1);

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j]) {
                    int temp = nums2[j];
                    for (int k = j; k < n2; k++) {
                        if (nums2[k] > temp) {
                            temp = nums2[k];
                            ans[i] = nums2[k];
                            break;
                        }
                    }

                    if (temp == nums2[j]) ans[i] = -1;
                    break;
                }
            }
        }

        return ans;
    }
};