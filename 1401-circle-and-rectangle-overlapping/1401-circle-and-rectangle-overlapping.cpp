class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1,
                      int x2, int y2) {
        if (sqrt((x1 - xCenter) * (x1 - xCenter) +
                 (y1 - yCenter) * (y1 - yCenter)) <= radius)
            return true;
        if (sqrt((x2 - xCenter) * (x2 - xCenter) +
                 (y1 - yCenter) * (y1 - yCenter)) <= radius)
            return true;
        if (sqrt((x1 - xCenter) * (x1 - xCenter) +
                 (y2 - yCenter) * (y2 - yCenter)) <= radius)
            return true;
        if (sqrt((x2 - xCenter) * (x2 - xCenter) +
                 (y2 - yCenter) * (y2 - yCenter)) <= radius)
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