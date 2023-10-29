class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int repeat = minutesToTest / minutesToDie;
        int pigs = 0;
        while (pigs <= 1000) {
            if (pow(repeat + 1, pigs) >= buckets) break;
            pigs++;
        }

        return pigs;
    }
};