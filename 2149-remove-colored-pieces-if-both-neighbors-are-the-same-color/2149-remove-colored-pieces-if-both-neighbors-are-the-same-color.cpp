class Solution {
public:
    bool winnerOfGame(string colors) {
        int aCnt = 0, bCnt = 0;
        int aWin = 0, bWin = 0;
        for (char color : colors) {
            if (color == 'A') {
                aCnt++;
                bCnt = 0;
                if (aCnt >= 3) {
                    aWin++;
                }
            } else {
                aCnt = 0;
                bCnt++;
                if (bCnt >= 3) {
                    bWin++;
                }   
            }
        }

        if (aWin > bWin)
            return true;
        
        return false;
    }
};