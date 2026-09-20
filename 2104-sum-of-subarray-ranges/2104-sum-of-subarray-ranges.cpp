class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        
        stack<int> st;
        stack<int> st2;
        vector<int> prevSmall(n), nextSmall(n), prevGreat(n), nextGreat(n);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            while (!st2.empty() && nums[st2.top()] <= nums[i]) st2.pop();

            prevSmall[i] = st.empty() ? -1 : st.top();
            prevGreat[i] = st2.empty() ? -1 : st2.top();

            st2.push(i);
            st.push(i);
        }

        while (!st.empty()) st.pop();
        while (!st2.empty()) st2.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            while (!st2.empty() && nums[st2.top()] < nums[i]) st2.pop();

            nextSmall[i] = st.empty() ? n : st.top();
            nextGreat[i] = st2.empty() ? n : st2.top();

            st.push(i);
            st2.push(i);
        }

        long long maxi = 0;
        long long mini = 0;

        for (int i = 0; i < n; i++) {
            maxi += 1LL * (nextGreat[i] - i) * (i - prevGreat[i]) * nums[i];
            mini += 1LL * (nextSmall[i] - i) * (i - prevSmall[i]) * nums[i];
        }

        return maxi - mini;
    }
};