class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, 
                      int x1, int y1, int x2, int y2) {
        int closestX = max(x1, min(x2, xCenter));
        int closestY = max(y1, min(y2, yCenter));

        long long dx = xCenter - closestX;
        long long dy = yCenter - closestY;

        return dx * dx + dy * dy <= 1LL * radius * radius;
    }
};