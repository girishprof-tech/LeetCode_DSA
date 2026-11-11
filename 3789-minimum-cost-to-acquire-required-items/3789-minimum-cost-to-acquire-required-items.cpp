class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if (need1 == 0 && need2 == 0) return 0;

        if (costBoth <= cost1 && costBoth <= cost2) {
            return need1 > need2 ? 1LL * need1 * costBoth : 1LL * need2 * costBoth;
        }

        if (costBoth <= cost2 && need1 < need2) {
            return 1LL * need2 * costBoth;
        }

        if (costBoth <= cost1 && need2 < need1) {
            return 1LL * need1 * costBoth;
        }

        if (cost1 + cost2 < costBoth) {
            return 1LL * cost1 * need1 + 1LL * cost2 * need2;
        }

        if (need1 < need2) {
            return 1LL * costBoth * need1 + 1LL * (need2 - need1) * cost2;
        }

        return 1LL * costBoth * need2 + 1LL * (need1 - need2) * cost1; 
    }
};