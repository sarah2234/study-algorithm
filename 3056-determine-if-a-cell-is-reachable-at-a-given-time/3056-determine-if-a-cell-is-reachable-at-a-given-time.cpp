class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int horizontalTime = abs(fx - sx);
        int verticalTime = abs(fy - sy);
        
        if (horizontalTime == 0 && verticalTime == 0) {
            if (t != 1) {
                return true;
            }
        } else {
            int maxTime = max(horizontalTime, verticalTime);
            if (maxTime <= t) {
                return true;
            }
        }
        
        return false;
    }
};