class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle = 0.5, minuteAngle = 6;
        double leftSide, rightSide;

        leftSide = abs((hour * 60 + minutes) * hourAngle - minutes * minuteAngle);
        rightSide = 360  - leftSide;

        return min(leftSide, rightSide);

    }
};