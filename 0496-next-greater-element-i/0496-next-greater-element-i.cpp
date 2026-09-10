class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> temp(n2);
        vector<int> ans(n1);

        stack<int> st;
        for (int i = n2 - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) st.pop();

            if (st.empty()) temp[i] = -1;
            else temp[i] = st.top();

            st.push(nums2[i]);
        }

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (nums1[i] == nums2[j]) {
                    ans[i] = temp[j];
                    break;
                }
            }
        }

        return ans;
    }
};