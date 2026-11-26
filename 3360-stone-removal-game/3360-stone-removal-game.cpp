class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10) return false;
        bool alice = true;

        for (int i = 10; i >= 1; i--) {
            if (alice) {
                if (i > n) return false;
                
                n -= i;
                alice = false;
            }
            else {
                if (i > n) return true;
                
                n -= i;
                alice = true;
            }
        }

        return true;
    }
};