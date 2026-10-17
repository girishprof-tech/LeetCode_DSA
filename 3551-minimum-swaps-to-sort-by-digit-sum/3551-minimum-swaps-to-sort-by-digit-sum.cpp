class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> arr(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            int sum = 0, num = nums[i];
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            arr[i] = {sum, nums[i], i};
        }
        sort(arr.begin(), arr.end());

        unordered_set<int> st;
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (st.count(i)) continue;

            st.insert(i);
            int j = arr[i][2];
            while (i != j) {
                st.insert(j);
                swaps++;
                j = arr[j][2];
            }
        }
        return swaps;
    }
};