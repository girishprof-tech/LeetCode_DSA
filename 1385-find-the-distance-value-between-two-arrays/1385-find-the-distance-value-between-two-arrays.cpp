class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int m = arr1.size();
        int n = arr2.size();

        int res = 0;
        for (int i = 0; i < m; i++) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (abs(arr1[i] - arr2[j]) > d) cnt++;
                else break;
            }

            if (cnt == n) res++;
        }

        return res;
    }
};