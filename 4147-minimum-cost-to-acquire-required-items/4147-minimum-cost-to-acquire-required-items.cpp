class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int one = min(cost1, costBoth);
        int two = min(cost2, costBoth - one);
        long long p1 = one * 1LL * need1 + 1LL * two * need2;

        one = min(cost2, costBoth);
        two = min(cost1, costBoth - one);
        long long p2 = 1LL * one * need2 + 1LL * two * need1;

        return max(p1, p2);
    }
};