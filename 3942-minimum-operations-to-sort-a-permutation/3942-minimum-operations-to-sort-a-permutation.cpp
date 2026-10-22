class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        bool asc = true, des = true;

        int start = find(nums.begin(), nums.end(), 0) - nums.begin();
        for (int i = 1; i < n; i++) {
            int val = nums[(start + i) % n];
        
            if (val != i) asc = false;
            if (val != n - i) des = false;

            if (!asc && !des) return -1;
        }

        if (asc) return min(start, n - start + 2);
        
        return min(n - start, start + 2);
    }
};