class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res = 0;
        bool found = true;
        for (auto m : arr1) {
            for (auto n : arr2) {
                if (abs(m - n) <= d) {
                    found = false;
                    break;
                }
                else found = true;
            }
            if (found) res++;
        }

        return res;
    }
};