class Solution {
public:
    const int MOD = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        stack<int> st;
        vector<int> prevSmall(n), nextSmall(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if (st.empty()) prevSmall[i] = -1;
            else prevSmall[i] = st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if (st.empty()) nextSmall[i] = n;
            else nextSmall[i] = st.top();
            st.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            long long left = i - prevSmall[i];
            long long right = nextSmall[i] - i;

            sum = (sum + (left * right * arr[i])) % MOD;
        }

        return sum;
    }
};