class Solution {
public:
    double dis(int xCenter, int yCenter, int x, int y) {
        return sqrt((x - xCenter) * (x - xCenter) +
                    (y - yCenter) * (y - yCenter));
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        if (dis(xCenter, yCenter, x1, y1) <= radius)
            return true;
        if (dis(xCenter, yCenter, x1, y2) <= radius)
            return true;
        if (dis(xCenter, yCenter, x2, y1) <= radius)
            return true;
        if (dis(xCenter, yCenter, x2, y2) <= radius)
            return true;

        if (y1 <= yCenter && y2 >= yCenter &&
            ((xCenter + radius >= x1 && xCenter - radius <= x1) ||
             (xCenter + radius >= x2 && xCenter - radius <= x2)))
            return true;
        if (x1 <= xCenter && x2 >= xCenter &&
            ((yCenter + radius >= y1 && yCenter - radius <= y1) ||
             (yCenter + radius >= y2 && yCenter - radius <= y2)))
            return true;

        if (xCenter - radius >= x1 && xCenter + radius <= x2 &&
            yCenter + radius <= y2 && yCenter - radius >= y1)
            return true;

        return false;
    }
};